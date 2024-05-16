#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<pair<int, int>>> v(n + 1);
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a, s});
        }

        vector<int> dis(n + 1, 1e9);
        priority_queue<pair<int, int>> pq;

        pq.push({0, c});
        dis[c] = 0;

        int answer = 0;
        set<int> se;
        while (!pq.empty()) {
            int node = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            answer = max(answer, dis[node]);
            se.insert(node);

            for (auto &i: v[node]) {
                int nxNode = i.first;
                int nxCost = cost + i.second;
                if (nxCost < dis[nxNode]) {
                    dis[nxNode] = nxCost;
                    pq.push({-nxCost, nxNode});
                }
            }
        }

        cout << se.size() << ' ' << answer << '\n';
    }
}