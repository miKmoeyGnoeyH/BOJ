#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int sum = 300;
    cin >> n >> m;

    bool *pages = new bool[n + 1];
    int *dp = new int[n + 1];
    fill_n(pages, n + 1, false);
    pages[0] = true;
    fill_n(dp, n + 1, 0);

    for(int i = 0; i < m; i++) {
        int page;
        cin >> page;
        pages[page] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(pages[i]) {
            dp[i] = dp[i - 1];
            sum += 2;
        }
        else {
            if(!pages[i - 1]) sum = dp[i] = dp[i - 1] + 2;
            else sum = dp[i] = min(dp[i - 1] + 7, sum + 2);
        }
    }

    cout << dp[n] << endl;

    delete[] dp;
    delete[] pages;
    return 0;
}