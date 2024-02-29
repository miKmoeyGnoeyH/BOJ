#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int **pas = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        pas[i] = new int[k + 1];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(i <= 1) {
                pas[i][j] = 1;
                continue;
            }
            if(j == 0 || j == i) {
                pas[i][j] = 1;
                continue;
            }
            else {
                pas[i][j] = (pas[i - 1][j - 1] + pas[i - 1][j]) % 10007;
            }
        }
    }

    cout << pas[n][k] << endl;

    for(int i = 0; i <= n; i++) delete[] pas[i];
    delete[] pas;
    return 0;
}