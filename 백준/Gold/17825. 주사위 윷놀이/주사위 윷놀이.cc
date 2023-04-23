#include <iostream>
#include <vector>
using namespace std;

int seq[4][100] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {10, 13, 16, 19, 25, 30, 35, 40},
    {20, 22, 24, 25, 30, 35, 40},
    {30, 28, 27, 26, 25, 30, 35, 40},
};
int maxSeq[4] = {21, 8, 7, 8};
pair<pair<int, int>, pair<int, int>> same[21] = {
    {{0, 5}, {1, 0}}, {{0, 10}, {2, 0}}, {{0, 15}, {3, 0}}, {{1, 4}, {2, 3}},  {{2, 3}, {3, 4}}, {{1, 4}, {3, 4}}, {{0, 20}, {1, 7}},
    {{1, 7}, {2, 6}}, {{2, 6}, {3, 7}},  {{1, 5}, {2, 4}},  {{1, 5}, {3, 5}},  {{2, 4}, {3, 5}}, {{1, 6}, {2, 5}}, {{1, 6}, {3, 6}},
    {{2, 5}, {3, 6}}, {{0, 20}, {1, 7}}, {{0, 20}, {2, 6}}, {{0, 20}, {3, 7}}, {{1, 7}, {2, 6}}, {{1, 7}, {3, 7}}, {{2, 6}, {3, 7}},
};

int dice[10], ans;
pair<int, int> locate[4];

void go(int idx, int sum, vector<pair<int, int>> v) {
    if (idx >= 10) {
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        pair<int, int> now = locate[i];
        int next = seq[locate[i].first][locate[i].second + dice[idx]];
        if (locate[i].first == -1) {
            continue;
        }
        if (next == 0) {
            locate[i] = {-1, 0};
        } else if (locate[i].first == 0 && next == 10) {
            locate[i] = {1, 0};
        } else if (locate[i].first == 0 && next == 20) {
            locate[i] = {2, 0};
        } else if (locate[i].first == 0 && next == 30) {
            locate[i] = {3, 0};
        } else {
            locate[i] = {locate[i].first, locate[i].second + dice[idx]};
        }
        bool flag = false;
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                continue;
            }
            if (locate[i].first != -1 && locate[i] == locate[j]) {
                flag = true;
                break;
            }
            for (int k = 0; k < 21; k++) {
                if ((same[k].first == locate[i] && same[k].second == locate[j]) || (same[k].first == locate[j] && same[k].second == locate[i])) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            locate[i] = now;
            continue;
        }
        v.push_back({i, next});
        go(idx + 1, sum + next, v);
        v.pop_back();
        locate[i] = now;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }
    go(0, 0, {});
    cout << ans;
}
// 4 1 4 4 4 4 3 2 2 4