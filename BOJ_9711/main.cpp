#include <stdio.h>
#include <vector>

using namespace std;

long long dp[10001] = {0, 1, 1};

int main() {
    int n;
    vector<long long> ans;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int p;
        long long q;
        scanf("%d %lld", &p, &q);

        for(int j = 3; j <= p; j++) {
            dp[j] = (dp[j - 1] + dp[j - 2]) % q;
        }
        ans.push_back(dp[p] % q);
    }

    for(int i = 0; i < n; i++) {
        printf("Case #%d: %lld\n", i + 1, ans[i]);
    }

    return 0;
}