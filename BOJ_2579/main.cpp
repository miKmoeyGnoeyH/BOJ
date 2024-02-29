#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int stairs[301] = { 0, };
    int s1[301] = { 0, };
    int s2[301] = { 0, };
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    for(int i = 1; i <= n; i++) {
        if(i - 1 <= 0) s1[i] = stairs[i];
        else s1[i] = stairs[i] + s2[i - 1];
        
        if(i - 2 <= 0) s2[i] = stairs[i];
        else s2[i] = max(stairs[i] + s1[i - 2], stairs[i] + s2[i - 2]);
    }

    cout << max(s1[n], s2[n]) << endl;

    return 0;
}