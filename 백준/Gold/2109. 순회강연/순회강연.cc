#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[10001];

bool compare(pair<int, int> &i, pair<int, int> &j) {
    return i.second < j.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int day = 1;
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> q;

    sort(a + 1, a + 1 + n, compare);

    int idx = 1;
    while (idx <= n) {
        while (day >= a[idx].second) {
            q.push(a[idx++].first);
            if (idx > n) {
                break;
            }
        }
        while (q.size() > day) {
            q.pop();
        }
        day++;
    }

    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans;
}
