#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, cnt = 0, j = 0;
    string s;
    
    cin >> n;
    cin >> s;

    for(int i = s.length() - 1; i >= 0;) {
        for(j = 0; j < 3; j++) {
            string subs = s.substr(i - j, j + 1);
        }
    }

    cout << cnt << endl;

    return 0;
}