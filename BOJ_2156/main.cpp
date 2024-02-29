#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> glasses(10001, -1);
vector<long long> dp(10001, -1);

long long solution(int n) {
    if(dp[n] != -1) return dp[n];
    else return dp[n] = max(max(solution(n - 1), solution(n - 2) + glasses[n]), solution(n - 3) + glasses[n - 1] + glasses[n]);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> glasses[i];
    }

    dp[1] = glasses[1];
    dp[2] = glasses[1] + glasses[2];
    dp[3] = max(max(glasses[1] + glasses[2], glasses[1] + glasses[3]), glasses[2] + glasses[3]);

    cout << solution(n) << endl;

    return 0;
}