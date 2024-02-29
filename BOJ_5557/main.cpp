#include <iostream>
#include <vector>

using namespace std;

int n;
int ans;
vector<int> v;

uint64_t solution(int index, int tmp) {
    if(index == n - 1) {
        if(tmp == 0) return 1;
        else return 0;
    }
    
    uint64_t ret = 0;
    ret += solution(index + 1, tmp - v[index]);
    ret += solution(index + 1, tmp + v[index]);

    return ret;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    cout << solution(1, v.back() - v[0]) << endl;
    return 0;
}