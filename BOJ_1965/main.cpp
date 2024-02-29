#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> boxes(n, 0);
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) cin >> boxes[i];
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(boxes[j] > boxes[i]) dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}