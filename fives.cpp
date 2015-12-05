#include <fstream>
#include <iostream>
using namespace std;

int fives (int n)
{
//  Declare objects.
    int result;
    if ((n%5) == 0)
    {
return 1; }
else {
return 0; }
 }

 int main(){
 int result,n;
 cout<<"enter n"<<endl;
 cin>>n;
 result=fives(n);
 cout<<result<<endl;
return 0;
 }