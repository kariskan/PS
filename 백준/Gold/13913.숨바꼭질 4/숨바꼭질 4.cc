#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visit[100001];
int order[100001];
int n, m;

int main() {
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int k = q.front();
        if (k == m) {
            cout << visit[k] << "\n";
            break;
        }
        q.pop();
        if (k - 1 >= 0 && !visit[k - 1]) {
            visit[k - 1] = visit[k] + 1;
            order[k - 1] = k;
            q.push(k - 1);
        }
        if (k + 1 < 100001 && !visit[k + 1]) {
            visit[k + 1] = visit[k] + 1;
            order[k + 1] = k;
            q.push(k + 1);
        }
        if (k * 2 < 100001 && !visit[k * 2]) {
            visit[k * 2] = visit[k] + 1;
            order[k * 2] = k;
            q.push(k * 2);
        }
    }
    vector<int> v;
    int idx = order[m];
    v.push_back(m);
    if (idx != 0)
        while (idx != n) {
            v.push_back(idx);
            idx = order[idx];
        }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (int i = 0; i < visit[m] + 1; i++)cout << v[i] << " ";
}