#include <iostream>

using namespace std;

int dp[51][51][51] = {0,};

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if(a > 20 || b > 20 || c > 20) {
        if(dp[a][b][c] != 0) return dp[a][b][c];
        else return dp[a][b][c] = w(20, 20, 20);
    }
    else if(a < b && b < c) {
        if(dp[a][b][c] != 0) return dp[a][b][c];
        else return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        if(dp[a][b][c] != 0) return dp[a][b][c];
        else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    while(!(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        cin >> a >> b >> c;
    }

    return 0;
}