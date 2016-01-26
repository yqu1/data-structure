#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 10000

void swap(int x, int y, int arr[]);
void median(int arr[], int first, int last);
long int QuickSort(int arr[], int first, int last);
int partition(int arr[], int first, int last);

void swap(int x, int y, int arr[])
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void median(int arr[], int first, int last)
{
	int mid = (first + last) / 2;

 	if(arr[first]>=arr[mid] && arr[first]>=arr[last])
    {
        if(arr[mid]>=arr[last]) swap(mid, first, arr);
        else swap(last, first, arr);
    }
    else if(arr[mid]>=arr[first] && arr[mid]>=arr[last])
    {
        if(arr[last]>=arr[first]) swap(last, first, arr);
    }
    else if(arr[mid]>=arr[first]) swap(mid, first, arr);
}

long int QuickSort(int arr[], int first, int last)
{	
	if(last <= first) return 0;
	long int sum = last - first;
	//median(arr, first, last);
	//swap(first, last, arr);
	int p = partition(arr, first, last);
	sum += QuickSort(arr, first, p - 1);
	sum += QuickSort(arr, p + 1, last);

	return sum;
}

int partition(int arr[], int first, int last)
{
	int pivot = arr[first];
	int i, j;
	i = first + 1;
	for(j = first + 1; j <= last; j++)
	{
		if(arr[j] < pivot)
		{
			swap(j, i, arr);
			i++;
		}
	}
	swap(i - 1, first, arr);
	return i - 1;
}

int main()
{
	int *arr = new int[SIZE];
	ifstream file("QuickSort.txt");
	int c;
	long int sum;
	for(int i = 0; i < SIZE; i ++)
	{
		file >> c;
		arr[i] = c;
	}
	sum = QuickSort(arr, 0, SIZE - 1);
	cout << "total number of comparisons is: " << sum << endl;

	delete[] arr;
}

