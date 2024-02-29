#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<uint64_t> t(n);
    vector<uint64_t> p(n);
    vector<uint64_t> dp(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    uint64_t max_val = 0;
    for(int i = 0; i < n; i++) {
        int index = i + t[i];
        if(index > n) continue;
        dp[index] = max(dp[index], dp[i] + p[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}