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

int n;
int monthSum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i <= 12; i++) {
        monthSum[i] += monthSum[i - 1];
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        int m, d;
        cin >> m >> d;
        p.first = monthSum[m - 1] + d;
        cin >> m >> d;
        p.second = monthSum[m - 1] + d - 1;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    // 3월 1일
    int now = monthSum[2] + 1;
    int idx = 0;
    int ans = 0;
    while (idx < n && now <= monthSum[11]) {
        int maxDay = -1;
        while (idx < n && v[idx].first <= now) {
            maxDay = max(maxDay, v[idx].second);
            idx++;
        }
        if (maxDay != -1) {
            now = maxDay + 1;
            ans++;
        } else {
            cout << 0;
            return 0;
        }
    }
    if (now > monthSum[11]) {
        cout << ans;
    } else {
        cout << 0;
    }
}
