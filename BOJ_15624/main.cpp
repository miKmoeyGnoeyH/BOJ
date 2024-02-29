#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<uint64_t> fib;

    cin >> n;
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2; i <= n; i++) {
        uint64_t num = (fib[i - 2] + fib[i - 1]) % 1000000007;
        fib.push_back(num);
    }

    cout << fib[n];

    return 0;
}