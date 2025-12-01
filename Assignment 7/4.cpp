#include<iostream>
using namespace std;
void divide(int arr[],int start,int end)
{
    if(start>=end)
    return;
    int mid=start+(end-start)/2;
    divide(arr,start,mid);
    divide(arr,mid+1,end);
    merge(arr,start,mid,end); 
}
void merge(int arr[],int start,int mid,int end)
{
    int l=mid-start+1;
    int r=end-mid;
    int left[l];
    int right[r];
    for(int i=0;i<l;i++)
    left[i]=arr[i+start];

    for(int j=0;j<r;j++)
    right[j]=arr[mid+1+j];

    int i=0,j=0,k=start;
    while(i<l && j<r)
    {
        if(left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<l)
        arr[k++]=left[i++];
    while(j<r)
        arr[k++]=right[j++];
}
int main()
{
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Eements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    divide(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}