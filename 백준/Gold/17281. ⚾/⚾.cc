#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int score[51][10];
int seq[10], vis[10];

int getScore() {
    int base[4] = {
        0,
    };
    int outCount = 0, now = 1, inning = 1, res = 0;

    while (inning <= n) {
        outCount = 0;
        base[0] = base[1] = base[2] = base[3] = 0;
        while (outCount < 3) {
            if (score[inning][seq[now]] == 0) {
                outCount++;
            } else {
                base[0] = 1;
                for (int i = 3; i >= 4 - score[inning][seq[now]]; i--) {
                    if (base[i]) {
                        base[i] = 0;
                        res++;
                    }
                }
                for (int i = 3 - score[inning][seq[now]]; i >= 0; i--) {
                    if (base[i]) {
                        base[i + score[inning][seq[now]]] = 1;
                        base[i] = 0;
                    }
                }
            }
            now++;
            if (now == 10) {
                now = 1;
            }
        }
        inning++;
    }

    return res;
}

void go(int idx) {
    if (idx > 9) {
        int s = getScore();
        if (ans < s) {
            ans = s;
            getScore();
        }
        return;
    }
    if (idx == 4) {
        if (vis[1]) {
            return;
        }
        seq[idx] = 1;
        vis[1] = 1;
        go(idx + 1);
        vis[1] = 0;
        seq[idx] = 0;
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                seq[idx] = i;
                go(idx + 1);
                vis[i] = 0;
                seq[idx] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> score[i][j];
            if (i == 1) {
                v.push_back(j);
            }
        }
    }

    go(1);
    cout << ans;
}