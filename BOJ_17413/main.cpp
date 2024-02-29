#include <iostream>
#include <string>

using namespace std;

string swap(string s, int start, int end) {
    int mid = (start + end) / 2;
    
    for(int i = 0; i <= mid - start; i++) {
        char tmp = s[start + i];
        s[start + i] = s[end - i];
        s[end - i] = tmp;
    }

    return s;
}

int main() {
    string s;
    getline(cin, s);

    for(int i = 0; i < s.length();) {
        int j = i;
        switch(s[j]) {
            case '<':
                while(j < s.length() && s[j] != '>') j++;
                i = j + 1;
                break;
            default:
                while(j < s.length() && s[j] != ' ' && s[j] != '<') j++;
                s = swap(s, i, j - 1);
                i = s[j] == ' ' ? j + 1 : j;
                break;
        }
    }

    cout << s << endl;

    return 0;
}