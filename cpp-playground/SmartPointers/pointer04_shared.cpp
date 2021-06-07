#include <memory>
#include <iostream>

class Foo
{
public:
  void doSomething() 
  {
    std::cout << "doSomething() called" << std::endl;
  }
};

class Bar
{
private:
  std::shared_ptr<Foo> pFoo;
public:
  Bar()
  {
    pFoo = std::shared_ptr<Foo>(new Foo());
  }
  std::shared_ptr<Foo> getFoo()
  {
    return pFoo;
  }
};

void SomeAction()
{
 	Bar* pBar = new Bar(); //with the Bar object, a new Foo is created and stored
	//reference counter = 1
 
	std::shared_ptr<Foo> pFoo = pBar->getFoo(); //a copy of the shared pointer is created
	//reference counter = 2
 
	pFoo->doSomething(); 
 
	delete pBar; //with pBar the private pFoo is destroyed
	//reference counter = 1
 
	return; //with the return the local pFoo is destroyed automatically 
	//reference counter = 0
	//internally the std::shared_ptr destroys the reference to the Foo object
}

void SomeOtherAction(std::shared_ptr<Bar> pBar)
{
	std::shared_ptr<Foo> pFoo = pBar->getFoo(); //a copy of the shared pointer is created
	//reference counter = 2
 
	pFoo->doSomething(); 
 
	return; //local pFoo is destroyed
	//reference counter = 1
}

int main(int argc, char *argv[]) 
{ 
  SomeAction();
}