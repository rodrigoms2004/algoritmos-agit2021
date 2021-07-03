//Source code do curso Algoritmos com C++ por Fabio Galuppo
//Ministrado em 2021 na Agit - https://www.agit.com.br/cursoalgoritmos.php
//Fabio Galuppo - http://member.acm.org/~fabiogaluppo - fabiogaluppo@acm.org
//Maio 2021

#include "bloom_filter.hpp"
#include "helpers_and_types.hpp"

#include <cstddef>
#include <string>
#include <cmath>
#include <iostream>

namespace bloom_filter
{
    static void test_interactive()
    {
        std::cout << "1: bloom filter of strings\n";
        std::cout << "2: bloom filter of ints\n";
        std::cout << "3: bloom filter of people's name\n";
        std::cout << "4: bloom filter's optimal number of bits\n";
        
        std::string cmd;
        while (std::cin >> cmd)
        {
            switch (cmd[0])
            {
            case '1':
            {
                std::size_t l, m, n;
                std::cout << "bloom filter length: "; std::cin >> l;
                std::cout << "bloom filter number of entries: "; std::cin >> m;
                std::cout << "bloom filter number of checks: "; std::cin >> n;
                bloom_filter::bloom_filter_minimalist<std::string> bf(l);
                for (std::string& s : generate_random_strings(m, 8))
                {
                    bf.add(s);
                    std::cout << bf.to_string(s) << "\n";
                }
                std::cout << "\nexists:\n";
                std::size_t count = 0;
                for (std::string& s : generate_random_strings(n, 8))
                {
                    if (bf.exists(s))
                    {
                        std::cout << bf.to_string(s) << "\n";
                        ++count;
                    }
                }
                std::cout << count << " match(es)\n";
            }
            break;
            case '2':
            {
                std::size_t l, m, n;
                std::cout << "bloom filter length: "; std::cin >> l;
                std::cout << "bloom filter number of entries: "; std::cin >> m;
                std::cout << "bloom filter number of checks: "; std::cin >> n;
                bloom_filter::bloom_filter_minimalist<int> bf(l);
                for (int i : generate_random_ints(m, 1, 99999))
                {
                    bf.add(i);
                    std::cout << bf.to_string(i) << "\n";
                }
                std::cout << "\nexists:\n";
                std::size_t count = 0;
                for (int i : generate_random_ints(n, 1, 99999999))
                {
                    if (bf.exists(i))
                    {
                        std::cout << bf.to_string(i) << "\n";
                        ++count;
                    }
                }
                std::cout << count << " match(es)\n";
            }
            break;
            case '3':
            {
                std::size_t l, m, n;
                std::cout << "bloom filter length: "; std::cin >> l;
                std::cout << "bloom filter number of entries: "; std::cin >> m;
                std::cout << "bloom filter number of checks: "; std::cin >> n;
                bloom_filter::bloom_filter_minimalist<std::string> bf(l);				
                std::vector<std::string> boys = load_male_first_names_file();
                std::vector<std::string> girls = load_female_first_names_file();
                std::vector<std::string> surnames = load_surnames_file();				
                for (person& p : generate_ordered_random_people(m, boys, girls, surnames))
                {
                    std::string s = p.first_name + " " + p.last_name;
                    bf.add(s);
                    std::cout << bf.to_string(s, 21) << "\n";
                }
                std::cout << "\nexists:\n";
                std::size_t count = 0;
                for (person& p : generate_random_people(m, boys, girls, surnames))
                {
                    std::string s = p.first_name + " " + p.last_name;
                    if (bf.exists(s))
                    {
                        std::cout << bf.to_string(s, 21) << "\n";
                        ++count;
                    }
                }
                std::cout << count << " match(es)\n";
            }
            break;
            case '4':
            {
                double e;
                int n;
                std::cout << "bloom filter false positive probability (0.0, 1.0): "; std::cin >> e;
                std::cout << "bloom filter number of entries: "; std::cin >> n;
                std::size_t m = -n * std::log(e) / std::pow(std::log(2.), 2.);
                std::cout << m << " bit(s)\n";
            }
            break;
            default:
                std::cout << "input ignored\n";
                break;
            }
        }
    }
}

int bloom_filter_main(int argc, char *argv[], bool run_tests, bool reg_benchmarks)
{
    using bloom_filter::test_interactive;

    if (run_tests)
    {
        test_interactive();
    }

    return 0;
}