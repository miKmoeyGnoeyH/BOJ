#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<uint64_t> fib;
    fib.push_back(1);
    fib.push_back(1);
    fib.push_back(1);
    fib.push_back(1);

    for(int i = 4; i <= n; i++) {
        uint64_t num = fib[i - 1] + fib[i - 3];
        fib.push_back(num);
    }

    cout << fib[n];

    return 0;
}