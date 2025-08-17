#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    if (n == 0) {
        cout << "Empty Array";
        return 1;
    }
    int arr[n];
    cout<<"Enter array elements: \n";
    for(int i=0;i<n;++i)
    cin>>arr[i];

    //Logic to Reverse Array
    for(int i=0;i<n/2;++i){
        arr[i]+=arr[n-1-i];
        arr[n-1-i]=arr[i]-arr[n-1-i];
        arr[i]-=arr[n-1-i];
    }

    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}