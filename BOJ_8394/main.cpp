#include <iostream>

using namespace std;

int main() {
    int dp[3] = {0, 1, 2};
    
    int n;
    cin >> n;

    if(n < 3) {
        cout << dp[n];
        return 0;
    }

    for(int i = 3; i <= n; i++) {
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = (dp[0] + dp[1]) % 10;
    }

    cout << dp[2];

    return 0;
}