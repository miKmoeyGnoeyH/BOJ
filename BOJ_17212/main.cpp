#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    uint64_t *dp = new uint64_t[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[i] = 0;
        else
            dp[i] = 100000;
    }

    for (int i = 0; i < n; i++)
    {
        if(i + 1 <= n) dp[i + 1] = dp[i + 1] < dp[i] + 1 ? dp[i + 1] : dp[i] + 1;
        if(i + 2 <= n) dp[i + 2] = dp[i + 2] < dp[i] + 1 ? dp[i + 2] : dp[i] + 1;
        if(i + 5 <= n) dp[i + 5] = dp[i + 5] < dp[i] + 1 ? dp[i + 5] : dp[i] + 1;
        if(i + 7 <= n) dp[i + 7] = dp[i + 7] < dp[i] + 1 ? dp[i + 7] : dp[i] + 1;
    }

    cout << dp[n];

    delete[] dp;
    return 0;
}