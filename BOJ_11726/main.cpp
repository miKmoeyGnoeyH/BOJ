#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    uint64_t result[1001] = {1, 1, 2};
    cin >> n;

    for(int i = 3; i <= n; i++) {
        result[i] = (result[i - 1] + result[i - 2]) % 10007;
    }

    cout << result[n];

    return 0;
}