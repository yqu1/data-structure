#include <iostream>
#include "node.h"

using namespace std;

class Queue: public List
{
	node* front;
	node* rear;
	node* head;

	public:

	Queue();
	void Enqueue(int x);
	void Dequeue();
	bool isEmpty();
	void Print();
};

void Queue::Print()
{
	node* temp=front;
	cout<<"list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}

Queue::Queue()
{
	front=NULL;
	rear=NULL;
}

bool Queue::isEmpty()
{
	if((front==NULL)&&(rear==NULL)) return true;
	else return false;
}

void Queue::Enqueue(int x)
{
	node* temp=GetNewNode(x);

	if(isEmpty()) 
	{
		front=temp;
		rear=temp;
		return;
	}

	rear->next=temp;
	rear=temp;		
}

void Queue::Dequeue()
{
	node* temp=front;
	if(isEmpty()) return;

	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}

	else
	{
		front=front->next;
	}

	delete temp;
}