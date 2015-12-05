#include "Heap.h"

int main()
{
	int n, element;
	vector<int> temp;
	cout<<"enter number of elements: "<<endl;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cout<<"enter element: "<<endl;
		cin>>element;
		temp.push_back(element);
	}
	Heap heap(temp);
	heap.print();
	cout<<"inserting item..."<<endl;
	heap.InsertItem(1);
	heap.print();
	cout<<"deleting min..."<<endl;
	heap.RemoveMin();
	heap.print();
	cout<<"sorting heap..."<<endl;
	temp=heap.HeapSort();

	for (int i=0; i<temp.size(); i++)
	{
		cout<<temp[i]<<" ";
	}

	cout<<endl;

}