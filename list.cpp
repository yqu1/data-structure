#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;


void insert(int n, int x)
{
	node* temp=new node;
	temp->data=x;

	if(head==NULL)
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

int see(int n)
{
	node* temp=head;
	for(int i=0; i<n-1; i++)
	{
		temp=temp->next;
	}

	return temp->data;
} 

int length()
{	
	int x(0);
	node* temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		x++;
	}

	return x;
}


void print()
{
	node* temp=head;
	cout<<"list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}

void Delete(int n)
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



int main()
{
	head=NULL;
	int n,x,l,d;

	cout<<"how many numbers?"<<endl;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cout<<"enter number: "<<endl;
		cin>>x;
		cout<<"enter location: "<<endl;
		cin>>l;

		insert(l,x);
		print();
	}

	cout<<"delete which location?"<<endl;
	cin>>d;
	Delete(d);
	print();
	cout<<"the 1st element is: "<<see(1)<<endl;

	cout<<"length of list is: "<<length()<<endl;

	return 0;
	
}
