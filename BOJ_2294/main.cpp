#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    set<int> coins;
    cin >> n >> k;

    uint64_t* dp = new uint64_t[k + 1];
    dp[0] = 0;
    for(int i = 1; i <= k; i++) {
        dp[i] = 10001;
    }


    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        coins.insert(x);
    }

    for(auto coin : coins) {
        for(int i = coin; i <= k; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if(dp[k] == 10001) cout << -1 << endl;
    else cout << dp[k] << endl;

    delete[] dp;
    return 0;
}