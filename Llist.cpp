#include "node.h"


int main()
{
	List list;
	int n,x,l,d;

	cout<<"how many numbers?"<<endl;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cout<<"enter number: "<<endl;
		cin>>x;
		cout<<"enter location: "<<endl;
		cin>>l;

		list.insert(x,l);
		list.print();
	}

	cout<<"delete which location?"<<endl;
	cin>>d;
	list.Delete(d);
    list.print();

	list.StackReverse();
	list.print();

	cout<<"insert last"<<endl;
	list.insertLast(3);
	list.print();

	cout<<list.length()<<endl;


	return 0;

}
