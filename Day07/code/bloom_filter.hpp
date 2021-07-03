//Source code do curso Algoritmos com C++ por Fabio Galuppo
//Ministrado em 2021 na Agit - https://www.agit.com.br/cursoalgoritmos.php
//Fabio Galuppo - http://member.acm.org/~fabiogaluppo - fabiogaluppo@acm.org
//Maio 2021

#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace bloom_filter
{
    namespace internal
    {
        //https://en.wikipedia.org/wiki/Circular_shift
        //adapted from rotl32c: https://blog.regehr.org/archives/1063
        inline static std::uint32_t rotate_left(std::uint32_t value, std::int8_t n)
        {
            return (value << n) | (value >> (-n & 31));
        }		

        //adapted from MurmurHash3_x86_32: https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp
        static std::uint32_t murmur3(const void* key, int len, std::uint32_t seed)
        {
            const std::uint8_t* data = static_cast<const std::uint8_t*>(key);
            const int nblocks = len / 4;

            std::uint32_t h1 = seed;

            const std::uint32_t c1 = 0xcc9e2d51;
            const std::uint32_t c2 = 0x1b873593;

            //----------
            // body

            const std::uint32_t * blocks = reinterpret_cast<const std::uint32_t*>(data + nblocks * 4);

            for (int i = -nblocks; i; i++)
            {
                std::uint32_t k1 = blocks[i];

                k1 *= c1;
                k1 = rotate_left(k1, 15);
                k1 *= c2;

                h1 ^= k1;
                h1 = rotate_left(h1, 13);
                h1 = h1 * 5 + 0xe6546b64;
            }

            //----------
            // tail

            const std::uint8_t * tail = reinterpret_cast<const std::uint8_t*>(data + nblocks * 4);

            std::uint32_t k1 = 0;

            switch (len & 3)
            {
            case 3: k1 ^= tail[2] << 16;
            case 2: k1 ^= tail[1] << 8;
            case 1: k1 ^= tail[0];
                k1 *= c1; k1 = rotate_left(k1, 15); k1 *= c2; h1 ^= k1;
            };

            //----------
            // finalization

            h1 ^= len;

            h1 ^= h1 >> 16;
            h1 *= 0x85ebca6b;
            h1 ^= h1 >> 13;
            h1 *= 0xc2b2ae35;
            h1 ^= h1 >> 16;			

            return h1;
        }

        //5.2 (Extended) Double Hashing Schemes: https://www.eecs.harvard.edu/~michaelm/postscripts/tr-02-05.pdf
        inline static std::uint32_t murmur3_double_hashing(const void* key, int len, std::uint32_t seed)
        {
            std::uint32_t h1 = murmur3(key, len, 0);
            std::uint32_t h2 = murmur3(key, len, h1);
            return h1 + h2;
        }

        template <typename T>
        struct murmur3_hash
        {
            const void* key; int len; std::uint32_t seed;
        };

        template <typename T>
        struct murmur3_double_hashing_hash
        {
            const void* key; int len; std::uint32_t seed;
        };
    }
}

namespace std
{
    template <typename T>
    struct hash<bloom_filter::internal::murmur3_hash<T>>
    {
        std::size_t operator()(const bloom_filter::internal::murmur3_hash<T>& args) const
        {
            return static_cast<std::size_t>(bloom_filter::internal::murmur3(args.key, args.len, args.seed));
        }
    };

    template <typename T>
    struct hash<bloom_filter::internal::murmur3_double_hashing_hash<T>>
    {
        std::size_t operator()(const bloom_filter::internal::murmur3_double_hashing_hash<T>& args) const
        {
            return static_cast<std::size_t>(bloom_filter::internal::murmur3_double_hashing(args.key, args.len, args.seed));
        }
    };
}

namespace bloom_filter
{
    namespace internal
    {
        template<typename T>
        struct bloom_filter_minimalist_pointer_size
        {
            inline static const void* get_pointer(const T& value) { return &value; }
            inline static int get_size(const T& value) { return static_cast<int>(sizeof(T)); }
        };

        template<>
        struct bloom_filter_minimalist_pointer_size<std::string>
        {
            inline static const void* get_pointer(const std::string& value) { return value.c_str(); }
            inline static int get_size(const std::string& value) { return static_cast<int>(value.size()); }
        };
        
        template<typename T>
        struct bloom_filter_minimalist_hashes : private bloom_filter_minimalist_pointer_size<T>
        {
            using Base = bloom_filter_minimalist_pointer_size<T>;			
            std::hash<internal::murmur3_hash<T>> h1;
            std::hash<internal::murmur3_double_hashing_hash<T>> h2;
            std::hash<T> h3;

            std::tuple<std::size_t, std::size_t, std::size_t> hashes_of(const T& value) const
            {
                const void* ptr = Base::get_pointer(value);
                int size = Base::get_size(value);
                return std::make_tuple(h1({ ptr, size, 0 }), h2({ ptr, size, 0 }), h3(value));
            }
        };
    }

    template<typename T>
    class bloom_filter_minimalist final : private internal::bloom_filter_minimalist_hashes<T>
    {
        using Base = internal::bloom_filter_minimalist_hashes<T>;
        std::vector<bool> bits;
    public:
        bloom_filter_minimalist(std::size_t length)
            : bits(length, false)
        {
            if (length == 0) throw std::runtime_error("length must be greater than 0");
        }

        void add(const T& value)
        {
            const std::size_t M = bits.size();
            std::size_t a, b, c;
            std::tie(a, b, c) = Base::hashes_of(value);
            bits[a % M] = true;
            bits[b % M] = true;
            bits[c % M] = true;
        }

        bool exists(const T& value) const
        {
            const std::size_t M = bits.size();
            std::size_t a, b, c;
            std::tie(a, b, c) = Base::hashes_of(value);
            return bits[a % M] && bits[b % M] && bits[c % M];
        }

        std::string to_string(const T& value, std::streamsize valuew = 8, std::streamsize hashw = 4) const
        {
            const std::size_t M = bits.size();
            std::size_t a, b, c;
            std::tie(a, b, c) = Base::hashes_of(value);
            std::stringstream ss;
            ss << std::setw(valuew) << value;
            ss << "[" << std::dec << std::setw(hashw) << (a % M) << "]";
            ss << "[" << std::dec << std::setw(hashw) << (b % M) << "]";
            ss << "[" << std::dec << std::setw(hashw) << (c % M) << "]";
            return std::move(ss.str());
        }
    };
}

#endif /* BLOOM_FILTER_HPP */