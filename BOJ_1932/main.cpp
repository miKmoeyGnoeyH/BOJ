#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<vector<long long>> tri;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        vector<long long> input;
        for(int j = 0; j < i + 1; j++) {
            long long a;
            cin >> a;
            input.push_back(a);
        }
        tri.push_back(input);
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            tri[i][j] = tri[i][j] + max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }

    cout << tri[0][0] << endl;

    return 0;
}