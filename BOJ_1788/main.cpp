#include <iostream>
#include <cstdlib>

using namespace std;

void fib_negative(long long* fib, int n) {
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 2] - fib[i - 1]) % 1000000000;
    }
}

void fib_positive(long long* fib, int n) {
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000000;
    }
}

int main() {
    int n;
    cin >> n;

    long long* fib = new long long[abs(n) + 1];

    if(n > 0) {
        fib_positive(fib, n);
    }
    else if(n < 0){
        fib_negative(fib, abs(n));
    }
    else {
        cout << 0 << endl << 0;
        return 0;
    }

    if(fib[abs(n)] > 0) {
        cout << 1 << endl;
    }
    else {
        cout << -1 << endl;
    }

    cout << abs(fib[abs(n)]);

    delete[] fib;
    return 0;
}