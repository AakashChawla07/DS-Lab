#include<iostream>
using namespace std;
void selectionSort(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int in=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<arr[i])
            in=j;
        }
        int temp=arr[i];
        arr[i]=arr[in];
        arr[in]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the ellements: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    selectionSort(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}