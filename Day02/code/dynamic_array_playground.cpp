//g++ -O3 dynamic_array_playground.cpp -o dynamic_array_playground.o

#include <iostream>
#include "dynamic_array.hpp"

using namespace std;

int main(int argc, char *agv[]) 
{
    dynamic_array::dynamic_array<int> xs;
    
    // 24 bytes = three size_t of 8 bytes each
    cout << "Size of the array in the stack: " << sizeof(xs) << endl; // 24 bytes in the stack + n bytes in the heap

    /* 
    In Day02/code/dynamic_array.hpp there are 
      private:
        std::size_t max_size, current_size; TWO size_t = 8 + 8 = 16 bytes
        T* items = nullptr; a generic pointer, in this case a int* pointer have 8 bytes (64 bit processor)
    };

    To check it, run code below:
    */
    // size_t i; int* j = nullptr;
    // cout << "size in bytes of size_t: " << sizeof(i) // 8 bytes
    //         << endl << "size in bytes of int*: " << sizeof(j) << endl; // 8 bytes

    xs.add(5); xs.add(23); xs.add(150); xs.add(3); xs.add(44); xs.add(38);
    cout << "Array size of " << xs.size() << " and capacity of " << xs.capacity() << endl;
    cout << "Address of the first element in the heap using data():  " << xs.data() << endl; // ex: 0x56423e3d62a0
    cout << "Address of the first element in the heap using begin(): " << xs.begin() << endl; // same addr above
    cout << "Address of the last element in the heap using end():    " << xs.end() << endl; // same addr above
    cout << "Value of the first element in the heap:                 " << *xs.begin() << endl; // 5
    cout << "Value of the last element in the heap:                  " << *xs.end() << endl; // 0 !!! why not 38 ?!

    // cout << endl << "Listing itens:" << endl;
    // for (size_t item : xs) 
    //     cout << item << endl;
    // cout << endl;

    for (size_t i = 0, l = xs.size(); i < l; ++i)
    {
        // cout << "Value at index " << i << " is " << xs.at(i) << endl;
        cout << "Value at index " << i << " is " << xs[i] << endl; // USING OPERATOR []
    }
    cout << endl;

    xs.remove(); xs.remove(); xs.remove(); xs.remove();
    cout << "Remove four elements" << endl;
    cout << "Array size of " << xs.size() << " and capacity of " << xs.capacity() << endl;
    cout << "Address of the first element in the heap using data():  " << xs.data() << endl; // ex: 0x56423e3d62a0
    cout << "Address of the first element in the heap using begin(): " << xs.begin() << endl; // same addr above
    cout << "Address of the last element in the heap using end():    " << xs.end() << endl; // same addr above
    cout << "Value of the first element in the heap:                 " << *xs.begin() << endl; // 5
    cout << "Value of the last element in the heap:                  " << *xs.end() << endl; // 150 !!! why not 23 ?!

    for (size_t i = 0, l = xs.size(); i < l; ++i)
    {
        // cout << "Value at index " << i << " is " << xs.at(i) << endl;
        cout << "Value at index " << i << " is " << xs[i] << endl; // USING OPERATOR []
    }
    cout << endl;
    return 0;
}
