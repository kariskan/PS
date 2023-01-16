#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200001;
int n;
vector<int> adj[MAX];
int cost[MAX];
int dp[MAX][2];

int solve(int node, bool stat) {
    int &ret = dp[node][stat];
    if (ret) return ret;
    if (adj[node].empty()) return 0;
    if (!stat) {
        for (int next : adj[node]) {
            int sel = solve(next, true);
            int no_sel = solve(next, false);
            ret += max(sel, no_sel);
        }
    } else {
        int no_sel_sum = 0;
        int sel_sum = 0;
        for (int next : adj[node]) {
            int sel = solve(next, true);
            int no_sel = solve(next, false);
            if (no_sel < sel)
                sel_sum += sel;
            else
                no_sel_sum += no_sel;
        }
        for (int next : adj[node]) {
            int sum = 0;
            int sel = solve(next, true);
            int no_sel = solve(next, false);
            if (no_sel < sel)
                sum = sel_sum + no_sel_sum - sel + no_sel +
                      cost[node] * cost[next];
            else
                sum = sel_sum + no_sel_sum + cost[node] * cost[next];
            ret = max(ret, sum);
        }
    }
    return ret;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    cout << max(solve(1, 0), solve(1, 1)) << "\n";
}