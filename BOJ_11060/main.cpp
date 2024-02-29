#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    vector<int> dp(n, 1001);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 1; j <= input[i]; j++) {
            if(i + j >= n) continue;
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    int result = dp[n - 1] == 1001 ? -1 : dp[n - 1];
    cout << result << endl;
    
    return 0;
}