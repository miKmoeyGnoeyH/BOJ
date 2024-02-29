#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool* arr = new bool[n];
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for(int i = 4; i < n; i++) {
        if(arr[i - 1] == 1 && arr[i - 3] == 1 && arr[i - 4] == 1) {
            arr[i] = 0;
        }
        else {
            arr[i] = 1;
        }
    }

    if(arr[n - 1] == 1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}