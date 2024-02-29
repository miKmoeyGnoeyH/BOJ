#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string code;
    int length;
    
    cin >> code;
    length = code.length();
    
    if(code[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    int *dp = new int[length + 1];

    dp[0] = 1;
    for(int i = 1; i < length; i++) {
        int ii = stoi(code.substr(i, 1));
        int ii_1 = stoi(code.substr(i - 1, 2));

        if(ii == 0) {
            if(ii_1 < 1 || ii_1 > 26) {
                cout << 0 << endl;
                delete[] dp;
                return 0;     
            }
            else {
                if(i > 1) dp[i] = dp[i - 2];
                else dp[i] = dp[i - 1];
            }
        }
        else {
            dp[i] = dp[i - 1];
            if(ii_1 >= 1 && ii_1 <= 26) {
                if(code[i - 1] == '0') continue;
                if(i > 1) dp[i] += dp[i - 2];
                else dp[i]++;                    
                dp[i] %= 1000000;
            }
        }
    }

    cout << dp[length - 1] << endl;

    delete[] dp;
    return 0;
}