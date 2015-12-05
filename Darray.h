#include <iostream>
using namespace std;

class Darray
{
	int size;
	int *array;

	public:
	Darray();
	Darray(int initSize);
	Darray(const Darray &original);
	Darray(int a[], int n);
	~Darray();

	void insert(int position, int value); 
  	int get(int position);  

  	int getSize();
  	void resize(int newSize);
  
 	int &operator[](int index);
  	bool operator==(Darray a);
 	bool operator!=(Darray a);
 	void operator=(const Darray& a);
 	void print();

};

Darray::Darray()
{
	size = 5;
	array = new int[5];
	for(int i=0; i<size; i++)
	{
		array[i]=0;
	}
}

Darray::Darray(int a[], int n)
{
	size=n;
	array=new int[n];
	for(int i=0; i<n; i++)
	{
		array[i]=a[i];
	}
}

Darray::Darray(int initSize)
{
	size=initSize;
	array=new int[initSize];
	for(int i=0; i<size; i++)
	{
		array[i]=0;
	}
}

Darray::Darray(const Darray &original)
{
	size=original.size;
	array=new int[size];

	for(int i=0; i<size; i++)
	{
		array[i]=original.array[i];
	}
}

Darray::~Darray()
{
	delete[] array; 
}

void Darray::insert(int position, int value) 
{
    array[position] = value;
}

void Darray::resize(int newSize)
{
	int* temp=new int[newSize];

	for(int i=0; i<size; i++)
	{
		temp[i]=array[i];
	}

	for(int i=size; i<newSize; i++)
	{
		temp[i]=0;
	}

	delete[] array;
	array=temp;
	size=newSize;
}

int Darray::get(int position)
{
	return array[position];
}

int Darray::getSize()
{
	return size;
}

int &Darray::operator[](int index)
{
  if ((index - 1) > size) 
  {
    resize(index + 1);
  }
	return array[index];
}

bool Darray::operator==(Darray a)
{
	bool flag=true;

	if(a.size!=size) return false;

	for(int i=0; i<size; i++)
	{
		if(array[i]!=a.array[i]) flag=false;
	}

	return flag;
}

void Darray::operator=(const Darray& a)
{
	if(this!=&a)
	{
		size=a.size;
		array=new int[size];

		for(int i=0; i<size; i++)
		{
			array[i]=a.array[i];
		}
	}
}

bool Darray::operator!=(Darray a)
{
	bool flag=false;

	if(a.size!=size) return true;

	for(int i=0; i<size; i++)
	{
		if(array[i]!=a.array[i]) flag=true;
	}

	return flag;
}

void Darray::print()
{
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<" ";
	}

	cout<<endl;
}