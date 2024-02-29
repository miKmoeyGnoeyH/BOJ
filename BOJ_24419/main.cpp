#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long **dp = new long long *[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new long long[n + 1];
    }

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    cout << dp[n][n] << " " << n * n << endl;

    for(int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}