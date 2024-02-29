#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) cin >> height[i]; 
    for(int i = n - 2; i >= 0; i--) {
        // if(height[i] != 0) {
        //     if(i + height[i] + 1 >= n) dp[i] = 1;
        //     else dp[i] = dp[i + height[i] + 1] + 1;
        // }
        // else dp[i] = dp[i + 1] + 1;
        if(height[i] == 0) dp[i] = dp[i + 1] + 1;
        else {
            if(i + height[i] + 1 >= n) dp[i] = 1;
            else dp[i] = dp[i + height[i] + 1] + 1;
        }
    }

    for(int i = 0; i < n - 1; i++) cout << dp[i] << " ";
    cout << dp[n - 1] << endl;

    return 0;
}