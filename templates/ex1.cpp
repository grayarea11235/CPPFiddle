// Simple function template

#include <iostream>

using namespace std;

template <class T>
T getMax(T a, T b) 
{
  T result;
  
  if (a > b)
    result = a;
  else
    result = b;

  return result;
}

int main(void)
{
  cout << "In main\n";

  int x = 7;
  int y = 12;

  int res = getMax<int>(x, y);

  cout << res << "\n";

  return 0;
}
