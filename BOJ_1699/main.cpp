#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *dp = new int[n + 1];
    fill_n(dp, n + 1, 100001);

    for(int i = 1; i * i <= n; i++) {
        dp[i * i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= n; j++) {
            int index = i + (j * j);
            if(index <= n) dp[index] = min(dp[index], dp[i] + 1);
        }
    }

    cout << dp[n] << endl;

    delete[] dp;
    return 0;
}