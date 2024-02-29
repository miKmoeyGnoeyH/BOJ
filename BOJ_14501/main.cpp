#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, uint64_t>> schedule;
    schedule.push_back(make_pair(0, 0));
    
    uint64_t *result = new uint64_t[n + 2];
    for(int i = 0; i < n + 2; i++) {
        result[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int t;
        uint64_t p;
        cin >> t >> p;

        schedule.push_back(make_pair(t, p));
    }

    for(int i = 1; i <= n; i++) {
        int index = i + schedule[i].first;
        
        if(index > n + 1) continue;
        
        for(int j = index; j <= n + 1; j++) {
            result[j] = result[i] + schedule[i].second > result[j] ? result[i] + schedule[i].second : result[j];
        }
    }

    cout << result[n + 1];

    delete[] result;
}