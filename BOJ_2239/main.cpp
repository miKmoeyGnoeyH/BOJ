#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins;
    uint64_t* dp = new uint64_t[k + 1];
    
    dp[0] = 1;
    for(int i = 1; i <= k; i++) {
        dp[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for(auto coin : coins) {
        for(int i = 1; i <= k; i++) {
            if(i - coin >= 0) dp[i] += dp[i - coin];
        }
    }

    cout << dp[k];
    delete[] dp;
    return 0;
}