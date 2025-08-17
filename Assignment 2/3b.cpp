#include <iostream>
using namespace std;
int findMissing(int arr[],int n){
    int beg=0,end=n-2;
    while(beg<=end){
        int mid =beg+ (end-beg)/2;
        if(arr[mid]!=mid+1)
        end = mid-1;
        else
        beg =mid+1;
    }
    return beg+1;
}
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n-1];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n-1; ++i)
        cin >> arr[i];

    cout<<"Missing num : "<< findMissing(arr,n)<<endl;
    return 0;
}
