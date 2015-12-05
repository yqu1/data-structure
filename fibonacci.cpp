#include <iostream>
using namespace std;

void Fibonacci(int m, int n, int t)
{
  if(t==0) return;
  cout<<m<<" ";
  Fibonacci(n,m+n,t-1);
}

int main()
{
  Fibonacci(1,1,33);
  return 0;
}
