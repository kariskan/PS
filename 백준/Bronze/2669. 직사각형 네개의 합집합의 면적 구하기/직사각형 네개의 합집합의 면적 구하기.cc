#include <iostream>
using namespace std;
pair<int, int> rec[4][2];
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> rec[i][j].first >> rec[i][j].second;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 4; k++) {
                if (i >= rec[k][0].first && j >= rec[k][0].second && i + 1 <= rec[k][1].first && j + 1 <= rec[k][1].second) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
}