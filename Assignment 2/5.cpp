#include <iostream>
using namespace std;

void input(int n, int arr[10][10]) {
    cout << "Enter elements of " << n << "x" << n << " matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element (" << i + 1 << "," << j + 1 << "): ";
            cin >> arr[i][j];
        }
    }
}

void display(int n, int arr[10][10]) {
    cout << "\nThe matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void diag(int matrix[10][10], int n) {
    int diagArr[10];
    for (int i = 0; i < n; i++) {
        diagArr[i] = matrix[i][i]; 
    }
    cout << "Diagonal elements stored in array: \n";
    for (int i = 0; i < n; i++) {
        cout << diagArr[i] << " ";
    }
    cout << endl;
}

void tridiag(int mat[10][10], int n) {
    int upper[n-1], mainDiag[n], lower[n-1];

    for (int i = 0; i < n; i++) {
        mainDiag[i] = mat[i][i]; 
        if (i < n - 1) {
            upper[i] = mat[i][i + 1];   
            lower[i] = mat[i + 1][i];   
        }
    }

    cout << "Main diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << mainDiag[i] << " ";
    }
    cout << endl;

    cout << "Upper diagonal: ";
    for (int i = 0; i < n - 1; i++) {
        cout << upper[i] << " ";
    }
    cout << endl;

    cout << "Lower diagonal: ";
    for (int i = 0; i < n - 1; i++) {
        cout << lower[i] << " ";
    }
    cout << endl;
}

void uprtriag(int mat[10][10], int n) {
    int upper[100]; 
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            upper[k++] = mat[i][j];
        }
    }
    cout << "Upper triangular elements stored in array: ";
    for (int i = 0; i < k; i++) {
        cout << upper[i] << " ";
    }
    cout << endl;
}

void lwrtriag(int mat[10][10], int n) {
    int lower[100]; 
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            lower[k++] = mat[i][j];
        }
    }
    cout << "Lower triangular elements stored in array: ";
    for (int i = 0; i < k; i++) {
        cout << lower[i] << " ";
    }
    cout << endl;
}

void symm(int mat[10][10], int n) {
    int symArr[100]; 
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            symArr[k++] = mat[i][j];
        }
    }
    cout << "symm triangle w/ diagonal: ";
    for (int i = 0; i < k; i++) {
        cout << symArr[i] << " ";
    }
    cout << endl;
}



int main() {
    int n;
    int m;
    int arr[10][10];
    cout << "Enter order of square matrix: ";
    cin >> n;
    input(n, arr);
    display(n, arr);
    cout << "enter the type of matrix it is, heres the menu \n"<<"1) Diagonal Matrix \n"<<"2) Tri-diagonal Matrix. \n"<<"3) Lower triangular Matrix. \n"<<"4) upper traingular matrix \n"<<"5) Symmetric Matrix \n";
    cin >> m;
    if(m==1){
        diag(arr,n);
    }
    else if(m==2){
        tridiag(arr,n);
    }
    else if(m==3){
        lwrtriag(arr,n);
    }
    else if(m==4){
        uprtriag(arr,n);
    }
    else if(m==5){
        symm(arr,n);
    }
    else{
        cout<<"invalid choice \n";
    }


    return 0;
}