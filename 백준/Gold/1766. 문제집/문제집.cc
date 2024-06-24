#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int n, m, in[32001];
vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        v[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();

        cout << node << ' ';
        for (auto &i: v[node]) {
            in[i]--;
            if (in[i] == 0) {
                pq.push(i);
            }
        }
    }
}