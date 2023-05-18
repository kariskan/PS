#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int> q1, q2;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            q1.push(a);
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            q2.push(a);
        }
    
        while ((int)q1.size() + (int)q2.size() != 1) {
            if (!q1.empty() && !q2.empty()) {
                if (q1.top() == q2.top()) {
                    q2.pop();
                } else if (q1.top() < q2.top()) {
                    q1.pop();
                } else {
                    q2.pop();
                }
            } else if (q1.empty()) {
                q2.pop();
            } else if (q2.empty()) {
                q1.pop();
            }
        }

        if (q1.empty()) {
            cout << "B\n";
        } else {
            cout << "S\n";
        }
    }
}