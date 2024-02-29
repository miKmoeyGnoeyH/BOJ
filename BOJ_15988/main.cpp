#include <iostream>

using namespace std;

long long dp[1000001] = {0, 1, 2, 4, };

int main() {
    int t;
    cin >> t;
    
    for(int i = 4; i <= 1000000; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}