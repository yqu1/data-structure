#include <iostream>
#include <vector>
using namespace std;



class Heap
{
	vector<int> heap;
	public: 
	Heap(vector<int> temp);
	int minElement();
	void shift(int a, int b);
	void Heapify();
	void DownHeap(int index);
	void InsertItem(int value);
	void RemoveMin();
	void UpHeap(int index);
	vector<int> HeapSort();
	void print();
	void arrayprint();
};

void Heap::arrayprint()
{
	for (int i=0; i<heap.size(); i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

vector<int> Heap::HeapSort()
{
	vector<int> temp=heap;
	vector<int> temp1;
	while(heap.size()!=0)
	{
		shift(0,heap.size()-1);
		temp1.push_back(heap[heap.size()-1]);
		heap.pop_back();
		DownHeap(0);
	}
	heap=temp;
	return temp1;
}

void Heap::print()
{
	int count(0), n(1), L(1);
	if(heap.size()==0) return;

	for(int i=0; i<n; i++)
	{
		if(i==heap.size()) break;

		cout<<heap[i]<<" ";
		if((i+1)>=n) 
		{
			n=n+2*L;
			L++;
			cout<<endl;
		}
	}

	cout<<endl;

}


Heap::Heap(vector<int> temp)
{
	for(int i=0; i<temp.size(); i++)
	{
		heap.push_back(temp[i]);
	}

	Heapify();
}

void Heap::InsertItem(int value)
{
	heap.push_back(value);
	UpHeap(heap.size()-1);
}

void Heap::RemoveMin()
{
	  int length = heap.size();

    if(length == 0)
    {
        return;
    }
    
    heap[0] = heap[length-1];
    heap.pop_back();

    DownHeap(0);
}

void Heap::shift(int i, int j)
{
	int temp=heap[i];
	heap[i]=heap[j];
	heap[j]=temp;
}


void Heap::DownHeap(int index)
{
	int length=heap.size();
	int leftchild=2*index+1;
	int rightchild=2*index+2;

	int minindex=index;

	if(leftchild>=length) return;

	if(heap[index]>heap[leftchild]) 
		minindex=leftchild;

	if(heap[minindex]>heap[rightchild]&&rightchild<length) 
		minindex=rightchild;

	if(minindex!=index)
	{
		shift(index,minindex);
		DownHeap(minindex);
	}

}

void Heap::UpHeap(int index)
{
	if(index==0) return;

	int ancestor=(index-1)/2;

	if(heap[ancestor]>heap[index])
	{
		shift(index,ancestor);
		UpHeap(ancestor);
	}
}

void Heap::Heapify()
{
	int length=heap.size();
	for(int i=length-1; i>=0; i--)
	{
		DownHeap(i);
	}
}


int Heap::minElement()
{
	if(heap.size()==0) return -1;
	return heap.at(1);
}





