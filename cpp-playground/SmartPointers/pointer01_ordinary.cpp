// https://en.cppreference.com/book/intro/smart_pointers
#include <iostream>

void my_func() 
{
  int* valuePtr = new int(15);
  std::cout << *valuePtr << std::endl; // 15
  int x = 45;
  std::cout << x << std::endl; // 45
  //...
  if (x == 45)
    return; // here we have a memory leak, valuePtr is not deleted
  //...
  delete valuePtr;
}

int main() 
{
  my_func();
  return 0;
}