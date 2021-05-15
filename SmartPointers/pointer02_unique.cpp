// https://en.cppreference.com/book/intro/smart_pointers
#include <iostream>
#include <memory>

void my_func() 
{
  std::unique_ptr<int> valuePtr(new int(15));
  std::cout << *valuePtr << std::endl; // 15
  int x = 45;
  std::cout << x << std::endl; // 45
  //...
  if (x == 45)
    return; // no meory leak anymore
  //...
}

int main() 
{
  my_func();
  return 0;
}