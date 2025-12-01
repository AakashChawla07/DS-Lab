#include<iostream>
using namespace std;
void QuickSort(int arr[],int start,int end)
{
    if(start>end)
    return;
    int pivot=partition(arr,start,end);
    QuickSort(arr,start,pivot-1);
    QuickSort(arr,pivot+1,end);
    return;  
}
int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        count++;
    }
    int in=count+start;
    int temp=arr[start];
    arr[start]=arr[in];
    arr[in]=temp;
    int i=start,j=end;
    while(i<in && j>in)
    {
        while(arr[i]<=pivot) 
        i++;
        while(arr[j]>pivot) 
        j--;
        if (i<in && j>in) 
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return in;
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    QuickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}