#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int j = 0; j < n; j++)
        {
            cin >> coins[j];
        }

        int m;
        cin >> m;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (auto j : coins)
        {
            for (int k = 0; k <= m - j; k++)
            {
                if (k != 0 && dp[k] == 0)
                    continue;
                dp[k + j] += dp[k];
            }
        }
        cout << dp[m] << endl;
    }

    return 0;
}