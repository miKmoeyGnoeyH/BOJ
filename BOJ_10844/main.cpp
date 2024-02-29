#include <iostream>
#include <cmath>

using namespace std;

unsigned long long dp[101][10];
unsigned long long results[101];

int main() {
    int n;
    cin >> n;

    dp[1][0] = 0;
    results[1] = 0;
    for(int j = 1; j <= 9; j++) {
        results[1] += dp[1][j] = 1;
    }

    for(int i = 2; i <= n; i++) {
        results[i] = 0;
        for(int j = 0; j <= 9; j++) {
            dp[i][j] = 0;
            if(j == 0) dp[i][j] = dp[i - 1][j + 1];
            else if(j == 9) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000);
            results[i] = (results[i] + dp[i][j]) % 1000000000;
        }
    }

    cout << results[n] << endl;

    return 0;
}