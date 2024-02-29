#include <iostream>
#include <algorithm>

using namespace std;

int dp_min[3] = {0, 0, 0};
int dp_max[3] = {0, 0, 0};

int main() {
    int n;
    int tmp_max[3];
    int tmp_min[3];
    cin >> n;

    for(int i = 0; i < n; i++) {
        int input[3];
        
        for(int j = 0; j < 3; j++) {
            cin >> input[j];
        }
        tmp_max[0] = max(dp_max[0], dp_max[1]) + input[0];
        tmp_min[0] = min(dp_min[0], dp_min[1]) + input[0];

        tmp_max[1] = max(max(dp_max[0], dp_max[1]), dp_max[2]) + input[1];
        tmp_min[1] = min(min(dp_min[0], dp_min[1]), dp_min[2]) + input[1];

        tmp_max[2] = max(dp_max[1], dp_max[2]) + input[2];
        tmp_min[2] = min(dp_min[1], dp_min[2]) + input[2];

        for(int j = 0; j < 3; j++) {
            dp_max[j] = tmp_max[j];
            dp_min[j] = tmp_min[j];
        }
    }

    int result_max = *max_element(&dp_max[0], &dp_max[0] + 3);
    int result_min = *min_element(&dp_min[0], &dp_min[0] + 3);

    cout << result_max << " " << result_min << endl;

    return 0;
}