#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    uint64_t *arr = new uint64_t[101];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;

    for(int i = 5; i <= 100; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }

    cin >> t;
    vector<uint64_t> results;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        results.push_back(arr[n]);
    }

    for (auto i : results) {
        cout << i << endl;
    }

    delete[] arr;
    return 0;
}