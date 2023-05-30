#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int child[100000];

int main() {
    priority_queue<int> q;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> child[i];
    }

    for (int i = 0; i < m; i++) {
        int now = child[i];
        if (q.empty() || q.top() < now) {
            cout << 0;
            return 0;
        }
        int c = q.top();
        q.pop();
        c -= now;
        if (c) {
            q.push(c);
        }
    }
    cout << 1;
}