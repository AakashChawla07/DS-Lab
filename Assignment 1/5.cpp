#include <iostream>
using namespace std;
const int m = 3, n = 3;
int arr[m][n];

void input() {
    cout << "Enter array elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void sumRows() {
    cout << "Sum of each row:\n";
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += arr[i][j];
        cout << "Row " << i << ": " << sum << endl;
    }
}

void sumColumns() {
    cout << "Sum of each column:\n";
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += arr[i][j];
        cout << "Column " << j << ": " << sum << endl;
    }
}

int main() {
    input();
    sumRows();
    sumColumns();
    return 0;
}
