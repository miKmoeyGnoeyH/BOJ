#include <iostream>

using namespace std;

long long dp1[100001] = {0, 1, 0, 1, 2,};
long long dp2[100001] = {0, 0, 1, 1, 0,};
long long dp3[100001] = {0, 0, 0, 1, 1,};

int main() {
    for(int i = 5; i <= 100000; i++) {
        dp1[i] = (dp2[i - 1] + dp3[i - 1]) % 1000000009;
        dp2[i] = (dp1[i - 2] + dp3[i - 2]) % 1000000009;
        dp3[i] = (dp1[i - 3] + dp2[i - 3]) % 1000000009;
    }
    
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n] + dp3[n]) % 1000000009 << endl;
    }

    return 0;
}