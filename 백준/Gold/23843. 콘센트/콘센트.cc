#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int a[10001], s[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    priority_queue<int, vector<int>, greater<> > q;
    int idx = n - 1;
    while (idx >= 0 && q.size() < m) {
        q.push(a[idx]);
        idx--;
        if (idx < 0) {
            break;
        }
    }
    for (int i = idx; i >= 0; i--) {
        int t = q.top() + a[i];
        q.pop();
        q.push(t);
    }

    int ans = 0;
    while (!q.empty()) {
        ans = q.top();
        q.pop();
    }
    cout << ans;
}
