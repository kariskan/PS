#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct p {
    int d;
    int h;
    int line;
    int i;

    bool operator<(const p &p1) const {
        if (d == p1.d) {
            if (h == p1.h) {
                return line > p1.line;
            }
            return h < p1.h;
        }
        return d < p1.d;
    }
};

int n, m, k;
vector<vector<p>> v;
int idx[100000];

int main() {
    cin >> n >> m >> k;
    v.resize(m);
    priority_queue<p> pq;
    int line = -1;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        line = (line + 1) % m;
        v[line].push_back({a, b, line, i});
    }
    for (int i = 0; i < v.size(); i++) {
        if (!v[i].empty()) {
            pq.push(v[i][0]);
            idx[i]++;
        }
    }
    int ans = 0;
    while (pq.top().i != k + 1) {
        p now = pq.top();
        pq.pop();
        if (v[now.line].size() > idx[now.line]) {
            pq.push(v[now.line][idx[now.line]++]);
        }
        ans++;
    }
    cout << ans;
}