#include <iostream>
#include <vector>
using namespace std;


void merge(int *,int, int , int );
void mergesort(int *a, int low, int high);
void merge(int *a, int low, int high, int mid);
void shift(int i, int j, vector<int> &temp);
void print(vector<int> temp);
void shellsort(vector<int> &temp);
void quicksort(vector<int> &temp, int first, int last);
int partition(vector<int> &temp, int first, int last);

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void shift(int i, int j, vector<int> &temp)
{
    int temp1=temp[i];
    temp[i]=temp[j];
    temp[j]=temp1;
}

void print(vector<int> temp)
{
    for(int i=0; i<temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }

    cout<<endl;
}

void shellsort(vector<int> &temp)
{
    int gap(5);
    while(gap>=1)
    {
        for(int i=0; i+gap<temp.size(); i++)
        {
           if(temp[i]>temp[i+gap])
           {
                shift(i, i+gap, temp);
                int j=i;
                while(j-gap>=0&&temp[j-gap]>temp[j])
                {
                     shift(j, j-gap, temp);
                     j=j-gap;
                }
           }


        }
        gap=gap/2;
    }

}

void quicksort(vector<int> &temp, int first, int last)
{
    int pivotlocation;

    if (first<last)
    {
        pivotlocation=partition(temp,first,last);
        quicksort(temp,first,pivotlocation-1);
        quicksort(temp,pivotlocation+1,last);
    }
}

int partition(vector<int> &temp, int first, int last)
{
    int pivot;
    int smallindex,index;
    shift(first,(first+last)/2,temp);
    pivot=temp[first];
    smallindex=first;

    for(index=first+1; index<=last; index++)
    {
        if(temp[index]<pivot)
        {
            smallindex++;
            shift(index,smallindex,temp);
        }       
    }

    shift(first,smallindex,temp);
    return smallindex;
}

void bucket(vector<int> &temp, int max)
{
    int *bucket=new int[max];
    int index(0);

    for(int i=0; i<temp.size(); i++)
    {
        bucket[temp[i]]++;
    }

    for(int i=0; i<max; i++)
    {
        if(bucket[i]!=0)
        {
            for(int j=0; j<bucket[i]; j++)
            {
                temp[index]=i;
                index++;
            }
        }
    }

    delete[] bucket;

}


