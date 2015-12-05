#include "sort.h" 

int main()
{
    int n,element;
    cout<<"input array size: "<<endl;
    cin>>n;
    vector<int> temp;

    for(int i=0; i<n; i++)
    {
        cout<<"input array element: "<<endl;
        cin>>element;
        temp.push_back(element);
    }

    cout<<"array sorted: "<<endl;
    bucket(temp,20);
    print(temp);

    return 0;
}