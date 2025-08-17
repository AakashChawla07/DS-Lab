#include<iostream>
using namespace std;
const int m=3,n=3;
int arr[m][n],arr2[n][m];

void add(int arr[][n],int m, int n){
    cout<<"Enter array elements: ";
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)
        cin>>arr[i][j];
    }
}

void transpose(){
    int trans[n][m];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            trans[j][i] = arr[i][j];
    }

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << trans[i][j] << " ";
        cout << "\n";
}
}
void matrix_mul(){
    int res[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
                res[i][j] += arr[i][k] * arr2[k][j];
        }
    }
    
    cout << "Resultant Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}
int main(){

    add(arr, m, n);
    add(arr2,n,m);
    transpose();
    matrix_mul();

}