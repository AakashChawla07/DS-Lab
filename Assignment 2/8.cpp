#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++){
        cout<<"enter element no. "<<i+1<<endl;
        cin >> A[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool diff = true;
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                diff = false;
                break;
            }
        }
        if (diff==1){
            count++;
        }
         
    }
    cout << "Total number of distinct elements: " << count << endl;
    return 0;
}