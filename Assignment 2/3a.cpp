#include <iostream>
using namespace std;
int findMissing(int arr[],int n){
    for(int i=0;i<n-1;++i){
        if(arr[i]!=i+1)
        return i+1;
    }
    return n;
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
