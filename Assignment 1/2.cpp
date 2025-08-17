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
    int unique=1;
    for (int i = 1; i < n; i++) {
    bool isDuplicate = false;
    for (int j = 0; j < unique; j++) {
        if (arr[i] == arr[j]) {
            isDuplicate = true;
            break;
        }
    }
    if (!isDuplicate)
        arr[unique++] = arr[i];
    }
    n=unique;
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "Duplicates removed";
}
