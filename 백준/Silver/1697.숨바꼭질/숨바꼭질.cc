#include <iostream>
#include <queue>
using namespace std;

int visit[100001];
int n, m;

int main() {
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int k = q.front();
        if (k == m) {
            cout << visit[k];
            break;
        }
        q.pop();
        if (k - 1 >= 0 && !visit[k - 1]) {
            visit[k - 1] = visit[k] + 1;
            q.push(k - 1);
        }
        if (k + 1 < 100001 && !visit[k + 1]) {
            visit[k + 1] = visit[k] + 1;
            q.push(k + 1);
        }
        if (k * 2 < 100001 && !visit[k * 2]) {
            visit[k * 2] = visit[k] + 1;
            q.push(k * 2);
        }
    }
}