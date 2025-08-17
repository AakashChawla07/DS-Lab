#include <iostream>
using namespace std;

int bin_search(int arr[], int size, int n) {
    int beg = 0, end = size - 1;
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == n)
            return mid;
        else if (arr[mid] < n)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int num;
    cout << "Enter element to search for: ";
    cin >> num;

    int result = bin_search(arr, n, num);
    if (result == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << result << "\n";

    return 0;
}
