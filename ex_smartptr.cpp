#include <stdio.h>

#include <iostream>

class Person
{
  int age;
  char* pName;
  
public:
  Person(): pName(0),age(0)
  {}

  Person(char* pName, int age): pName(pName), age(age)
  {}
  
  ~Person()
  {}
  
  void Display()
  {
    printf("Name = %s Age = %d \n", pName, age);
  }
  
  void Shout()
  {
    printf("Ooooooooooooooooo");
  } 
};


template < typename T > class SP
{
private:
  T*    pData; // Generic pointer to be stored
public:
  SP(T* pValue) : pData(pValue)
  {
  }
  ~SP()
  {
    printf("Inside the spmart pointer destructor\n");
    delete pData;
  }

  T& operator* ()
  {
    return *pData;
  }

  T* operator-> ()
  {
    return pData;
  }
};

int main()
{
  printf("Chickens\n");

  SP<Person> p(new Person("Scott", 25));

  p->Display();

  // Dont need to delete Person pointer..

  return 0;
}

