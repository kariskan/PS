#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mp, mf, ms, mv;
    cin >> mp >> mf >> ms >> mv;
    int arr[15][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = -1;
    vector<int> v;

    for (int i = 0; i < (1 << n); i++) {
        int tp = 0, tf = 0, ts = 0, tv = 0;
        int cost = 0;
        vector<int> t;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tp += arr[j][0];
                tf += arr[j][1];
                ts += arr[j][2];
                tv += arr[j][3];
                cost += arr[j][4];
                t.push_back(j + 1);
            }
        }
        if (tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
            if (ans == -1 || ans >= cost) {
                if (ans == -1 || ans > cost) {
                    ans = cost;
                    v = t;
                } else {
                    bool flag = false;
                    for (int j = 0; j < min(v.size(), t.size()); j++) {
                        if (v[j] < t[j]) {
                            flag = true;
                            break;
                        } else if (v[j] > t[j]) {
                            v = t;
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        if (v.size() > t.size()) {
                            v = t;
                        }
                    }
                }
            }
        }
    }

    if (ans == -1) {
        cout << -1;
    } else {
        cout << ans << '\n';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
    }
}
