#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[1000000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    pq.push(a[0].second);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() <= a[i].first) {
            pq.pop();
        }
        pq.push(a[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
}