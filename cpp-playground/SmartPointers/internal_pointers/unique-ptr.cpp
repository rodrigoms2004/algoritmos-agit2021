// g++ -O3 unique-ptr.cpp -o unique-ptr.o

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class ObjectXpto 
{
private:
  string data;
  int number = 20;
public:
  ObjectXpto(string str) : data(str){}

  void printData() 
  {
    cout << data << endl;
  }

  void compute()
  {
    unique_ptr<int> data_ptr = make_unique<int>();
    *data_ptr = number;
    *data_ptr += 20;

    cout << "Value of number =" << *data_ptr << endl;
  } // data_ptr goes out of scope here: it is automatically destroyed

  void compute(unique_ptr<int[]> p) {}
};


int main(int argc, char *argv[]) 
{
  // ObjectXpto* obj = new ObjectXpto("Lamp");
  // obj->printData();

  // unique_ptr<int>         p1(new int);
  // unique_ptr<int[]>       p2(new int[50]);
  // unique_ptr<ObjectXpto>  p3(new ObjectXpto("Lamp"));

  unique_ptr<int>         p1 = make_unique<int>();
  unique_ptr<int[]>       p2 = make_unique<int[]>(50);
  unique_ptr<ObjectXpto>  p3 = make_unique<ObjectXpto>("Lamp");

  int x = 5;
  *p1 = x;
  cout << "p1 = " << *p1 << endl;

  p2[49] = x;
  cout << "p2[49] = " << p2[49] << endl;
  
  p3->printData();
  p3->compute();

  // unique_ptr<int[]> ptr = make_unique<int[]>(1024);
  // unique_ptr<int[]> ptr_copy = ptr; // ERROR! Copy is not allowed
  // p3->compute(ptr); // ERROR! ptr is passed by copy, and copy  is not allowed



}