#include "Dlist.h"

int main()
{
	Dlist list;
	int n,x,l,d;

	cout<<"how many numbers?"<<endl;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cout<<"enter number: "<<endl;
		cin>>x;
		cout<<"enter location: "<<endl;
		cin>>l;

		list.Insert(x,l);
		list.print();
		list.ReversePrint();
	}




	return 0;
}