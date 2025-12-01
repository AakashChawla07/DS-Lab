#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0 && arr[j]<arr[j-1];j--)
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
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
    insertionSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}