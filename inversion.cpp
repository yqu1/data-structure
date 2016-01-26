#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define SIZE 100000

long int mergesort(int arr[], int temp[], int left, int right);
long int merge(int arr[], int temp[], int mid, int left, int right);

long int mergesort(int arr[], int temp[], int left, int right)
{
	int mid;
	long int inv_count(0);

	if(right > left)
	{
		mid = (right + left) / 2;
		inv_count += mergesort(arr, temp, left, mid);
		inv_count += mergesort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, mid + 1, left, right);
	}

	return inv_count;
}

long int merge(int arr[], int temp[], int mid, int left, int right)
{
	int i(left), j(mid), k(left);
	long int inv_count(0); 

	while(i <= mid - 1 && j <= right)
	{
		if(arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}

		else
		{
			temp[k++] = arr[j++];
			inv_count += (mid - i);
		}
	}

	while(i <= mid - 1)
	{
		temp[k++] = arr[i++];
	}

	while(j <= right)
	{
		temp[k++] = arr[j++];
	}

	for (long int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}

	return inv_count;
}

int main()
{
	ifstream file("IntegerArray.txt");
	int* arr = new int[SIZE];
	int c;
	long int inv_count;

	for(int i = 0; i < SIZE; i++)
	{
		file >> c;
		arr[i] = c;
	}

	int* temp = new int[SIZE];

	inv_count = mergesort(arr, temp, 0, SIZE - 1);

	cout << "number of inversions in the file is: " << inv_count << endl;

	delete[] arr;
	delete[] temp;

	file.close();
}
