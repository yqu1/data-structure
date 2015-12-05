#include "queue.h"

int main()
{
	int n,x;
	Queue queue;
	cout<<"how many elements?"<<endl;
	cin>>n;

	for (int i=0; i<n; i++)
	{
		cout<<"enter value: "<<endl;
		cin>>x;
		queue.Enqueue(x);
	}

	cout<<"dequeueing..."<<endl;
	queue.Dequeue();
	queue.Print();
}
