#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    uint64_t** dp = new uint64_t*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new uint64_t[m];
    }

    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 0; i < m; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
        }
    }

    cout << dp[n - 1][m - 1];

    for(int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}