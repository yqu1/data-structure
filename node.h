#include <iostream>
#include <stack>
using namespace std;

struct node
{
	int data;
	node* next;
};

class List
{
	node* head;

	public:
	List();
	~List();
	void insert(int x, int n);
	void insertLast(int x);
	int length();
	void Delete(int n);
	void DeleteAll();
	void print();
	void reverse();
	void StackReverse();
	node* GetNewNode(int x);
	int operator[] (int n);
};

int List::length()
{
	node* temp=head;
	int l(0);
	while(temp!=NULL)
	{
		temp=temp->next;
		l++;
	}

	return l;
}

int List::operator[] (int n)
{
	node* temp=head;

	for(int i = 0; i < n; i ++)
	{
		temp=temp->next;
	}

	return temp->data;
}

void List::insertLast(int x)
{
	if(head==NULL)
	{
		insert(x,1);
		return;
	}

	node* temp=new struct node;
	temp->data=x;
	temp->next=NULL;
	node* temp1=head;

	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}

	temp1->next=temp;	
}

List::~List()
{
	DeleteAll();
}

void List::DeleteAll()
{
	while(head!=NULL)
	{
		Delete(1);
	}
}

node* List::GetNewNode(int x)
{
	node* temp=new struct node;
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void List::StackReverse()
{
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
		return;
	}

	stack<struct node* > S;
	node* temp=head;

	while(temp!=NULL)
	{
		S.push(temp);
		temp=temp->next;
	}

	temp=S.top();
	head=temp;
	S.pop();

	while(!S.empty())
	{
		temp->next=S.top();
		S.pop();
		temp=temp->next;
	}

	temp->next=NULL;

}


List::List()
{
	head=NULL;
}


void List::insert(int x, int n)
{
	node* temp=new node;
	temp->data=x;

	if(n==1)
	{
		temp->next=head;
		head=temp;
	}

	else 
	{
		node* temp1=head;
		for (int i = 0; i < n-2; i ++)
		{
			temp1=temp1->next;
		}

		temp->next=temp1->next;
		temp1->next=temp;
	}

}

void List::Delete(int n)
{
	node* temp=head;

	if (n==1)
	{
		head=temp->next;
		delete temp;
	}

	else
	{
		for(int i=0; i<n-2; i++)
		{
			temp=temp->next;
		}

		node* temp1=temp->next;
		temp->next=temp1->next;
		delete temp1;
	}
}

void List::print()
{
	node* temp=head;
	if(head==NULL)
	{
		cout<<"list is empty!"<<endl;
		return;
	}

	cout<<"list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}


void List::reverse()
{
	node *Cur, *next, *prev;
	Cur=head;
	prev=NULL;

	while(Cur!=NULL)
	{
		next=Cur->next;
		Cur->next=prev;
		prev=Cur;
		Cur=next;
	}

	head=prev;

}


