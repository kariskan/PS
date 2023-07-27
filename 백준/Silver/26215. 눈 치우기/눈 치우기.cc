#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    int ans = 0;
    while (!pq.empty()) {
        if (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a - 1 != 0) {
                pq.push(a - 1);
            }
            if (b - 1 != 0) {
                pq.push(b - 1);
            }
        } else {
            int a = pq.top();
            pq.pop();
            if (a - 1 != 0) {
                pq.push(a - 1);
            }
        }
        ans++;
    }
    if (ans > 1440) {
        cout << -1;
    } else {
        cout << ans;
    }
}