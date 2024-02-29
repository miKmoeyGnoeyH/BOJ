#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        uint64_t result = 1;

        while(b) {
            if(b % 2) result *= a;
            a *= a;
            a %= 10;
            b /= 2;
        }

        result %= 10;
        if(result == 0) result = 10;

        cout << result << endl;
    }
}