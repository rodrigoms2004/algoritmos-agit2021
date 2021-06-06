#include "linear_search.hpp"
#include "helpers_and_types.hpp"

#include <cstddef>
#include <string>
#include <iostream>

#include "dynamic_array.hpp"
#include <vector>
#include <algorithm>

// g++ -O3 linear_search_playground.cpp -o linear_search_playground.o

namespace playground 
{
    static std::vector<std::string> get_singleton_test_vector()
    {
        static std::vector<std::string> xs = generate_random_strings(100, 5); // generates 100 string with length of 5 characters 
        return xs;
    }

    static std::string get_target()
    {
        return "?????";
    }

    static void dynamic_array_linear_search()
    {
        std::vector<std::string> ys = get_singleton_test_vector();
        dynamic_array::dynamic_array<std::string> xs;
        std::string target = get_target();

        // std::cout <<ys.size() << '\n';
        for (int i = 0; i < ys.size(); ++i)
            xs.add(ys[i % ys.size()]);

        xs.add(target);
        std::size_t pos = linear_search::linear_search(xs, target);

        std::cout << pos << '\n';
    }

    static void vector_linear_search()
    {
        std::vector<std::string> xs = get_singleton_test_vector();
        std::string target = get_target();

        xs.push_back("XPTO1");
        xs.push_back(target);
        xs.push_back("XPTO2");
        xs.push_back("XPTO3");
        std::size_t pos = linear_search::linear_search(xs, target);

        std::cout << pos << '\n';

        // for (auto i : xs)
        //     std::cout << i << std::endl;
    }

    static void vector_linear_search_iterator()
    {
        std::vector<std::string> xs = get_singleton_test_vector();
        std::string target = get_target();

        xs.push_back("XPTO1");
        xs.push_back(target);
        xs.push_back("XPTO2");
        xs.push_back("XPTO3");
        // std::vector<std::string>::iterator iter = std::find(xs.begin(), xs.end(), target);
        std::vector<std::string>::iterator iter = linear_search::linear_search_if(xs.begin(), xs.end(), [&](const std::string& x) { return x == target; });

        std::cout << *iter << '\n';
    }
}

//std::string* iter = linear_search_if(xs.begin(), xs.end(), [&](const std::string& x) { return x == target; });
//std::string* iter = find_if(xs.begin(), xs.end(), [&](const std::string& x) { return x == target; });
int main(int argc, char *argv[])
{

    playground::dynamic_array_linear_search();
    playground::vector_linear_search();
    playground::vector_linear_search_iterator();

    // for (auto i : xs) {
    //     std::cout<< i << std::endl;
    // }
    return 0;
}

