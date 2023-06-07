#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq[100];
int n, m, ans, score[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            pq[i].push(a);
        }
    }
    for (int j = 0; j < m; j++) {
        int ma = 0;
        for (int i = 0; i < n; i++) {
            ma = max(ma, pq[i].top());
        }
        for (int i = 0; i < n; i++) {
            if (pq[i].top() == ma) {
                score[i]++;
                ans = max(ans, score[i]);
            }
            pq[i].pop();
        }
    }
    for (int i = 0; i < n; i++) {
        if (score[i] == ans) {
            cout << i + 1 << '\n';
        }
    }
}