#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    int* dp = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min_val = arr[0];
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], arr[i] - min_val);
        min_val = min(arr[i], min_val);
    }

    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    delete[] arr;
    delete[] dp;

    return 0;
}