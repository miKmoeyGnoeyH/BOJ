#include <iostream>

using namespace std;

int main() {
    uint64_t dp[51];
    dp[0] = dp[1] = 1;
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
    }

    cout << dp[n];

    return 0;
}