#include <vector>
#include <iostream>
using namespac std;

int main()
{
	int A[]={1,2,3,4,5,6,7};
	int B[]={2,4,5,8,9};
	Darray a(A,7);
	Darray b(B,5);
	Darray c(merge(a,b));
	c.print();

}