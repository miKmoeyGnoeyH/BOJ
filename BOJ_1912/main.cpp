#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        arr[i] = max(arr[i], arr[i] + arr[i - 1]);
    }

    cout << *max_element(arr, arr + n) << endl;

    delete[] arr;
    return 0;
}