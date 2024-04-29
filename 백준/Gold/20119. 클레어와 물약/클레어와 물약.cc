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
    int in[200001], vis[200001], inp[200001];
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[a].push_back(i);
            in[i]++;
        }
        cin >> inp[i];
    }
    int l;
    cin >> l;
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < l; i++) {
        int a;
        cin >> a;
        q.push(a);
        ans.push_back(a);
        vis[a]=1;
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            in[v[node][i]]--;
            if (in[v[node][i]] == 0 && !vis[inp[v[node][i]]]) {
                q.push(inp[v[node][i]]);
                vis[inp[v[node][i]]]=1;
                ans.push_back(inp[v[node][i]]);
            }
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int a: ans) {
        cout << a << ' ';
    }
}