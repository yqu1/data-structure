#include <iostream>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};

class Dlist
{
	node* head;

	public:
	Dlist();
	void InsertAtHead(int x);
	void InsertAtTail(int x);
	node* GetNewNode(int x);
	void Insert(int x, int n);
	void ReversePrint();
	void print();
};

Dlist::Dlist()
{
	head=NULL;
}

node* Dlist::GetNewNode(int x)
{
	node* node=new struct node;
	node->data=x;
	node->prev=NULL;
	node->next=NULL;
	return node;
}

void Dlist::InsertAtHead(int x)
{
	node* node=GetNewNode(x);

	if(head==NULL)
	{
		head=node;
		return;
	}

	head->prev=node;
	node->next=head;
	head=node;
}

void Dlist::print()
{
	node* temp2=head;
	cout<<"list is: ";
	while(temp2!=NULL)
	{
		cout<<temp2->data;
		temp2=temp2->next;
	}
	cout<<endl;
}

void Dlist::ReversePrint()
{
	node* temp=head;
	cout<<"reverse list is: ";

	while (temp->next!=NULL)
	{
		temp=temp->next;
	}

	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->prev;
	}

	cout<<endl;
}

void Dlist::InsertAtTail(int x)
{
	node* temp1=head;
	node* node=GetNewNode(x);

	if(head==NULL)
	{
		head=node;
		return;
	}

	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}

	temp1->next=node;
	node->prev=temp1;
	node->next=NULL;

}

void Dlist::Insert(int x, int n)
{
	
	
	if(n==1)
	{
		InsertAtHead(x);
		return;
	}

	node* temp=head;

	for (int i=0; i<n-2; i++)
	{
		temp=temp->next;
	}

	if(temp->next==NULL)
	{
		InsertAtTail(x);
		return;
	}

	node* node=GetNewNode(x);

	node->next=temp->next;
	temp->next=node;
	node->prev=temp;
	(node->next)->prev=node;

}
