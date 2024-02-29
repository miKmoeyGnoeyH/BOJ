#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, k;
    cin >> a >> k;

    int* dp = new int[k + 1];
    fill_n(dp, k + 1, 1000001);
    dp[a] = 0;

    for(int i = a; i < k; i++) {
        if(i * 2 <= k)
            dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
    }

    cout << dp[k] << endl;

    delete[] dp;
    return 0;
}