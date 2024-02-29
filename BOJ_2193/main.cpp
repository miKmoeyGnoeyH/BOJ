#include <iostream>

using namespace std;

int main() {
    uint64_t* binaries = new uint64_t[90];
    binaries[0] = 1;
    binaries[1] = 1;

    for(int i = 2; i < 90; i++) {
        binaries[i] = binaries[i - 1] + binaries[i - 2];
    }

    int n;
    cin >> n;

    cout << binaries[n - 1];

    return 0;
}