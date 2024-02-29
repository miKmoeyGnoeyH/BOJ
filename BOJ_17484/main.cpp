#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> dp;
int dir[3] = {-1, 0, 1};
int ans = 601;

int solution(int i, int j, int prev_dir) {
    if(i == n) return 0;

    int ret = 601;

    for(int k = 0; k < 3; k++) {
        if(prev_dir == dir[k]) continue;
        if(j + dir[k] < 0 || j + dir[k] >= m) continue;
        ret = min(ret, solution(i + 1, j + dir[k], dir[k]) + dp[i][j]);
    }

    return ret;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        vector<int> v;
        for(int j = 0; j < m; j++) {
            int e;
            cin >> e;
            v.push_back(e);
        }
        dp.push_back(v);
    }

    for(int i = 0; i < m; i++) {
        ans = min(ans, solution(0, i, 100));
    }

    cout << ans;

    return 0;
}