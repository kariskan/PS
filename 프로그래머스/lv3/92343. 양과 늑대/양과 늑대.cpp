#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
vector<int> info;
int ans = 0;
void go(int node, int s, int w, vector<int> q) {
    s += info[node] ^ 1;
    w += info[node];
    if (s <= w) return;
    ans = max(ans, s);
    for (int i = 0; i < v[node].size(); i++) {
        q.push_back(v[node][i]);
    }
    for (int i = 0; i < q.size(); i++) {
        vector<int> t = q;
        t.erase(t.begin() + i);
        go(q[i], s, w, t);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    ::info = info;
    v.resize(info.size());

    for (vector<int> e : edges) {
        v[e[0]].push_back(e[1]);
    }
    go(0, 0, 0, {});
    return ans;
}