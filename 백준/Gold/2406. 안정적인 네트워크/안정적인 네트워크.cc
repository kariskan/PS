#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, p[1001];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    p[a] = min(a, b);
    p[b] = min(a, b);
}

int main() {
    cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		p[i] = i;
	}

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)) {
            Union(a, b);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            v.push_back({a, {i, j}});
        }
    }

    sort(v.begin(), v.end());
    int X = 0, K = 0;
    vector<pair<int, int>> ans;

    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;

        if (n1 != 1 && n2 != 1 && Find(n1) != Find(n2)) {
            Union(n1, n2);
            X += cost;
            K++;
            ans.push_back({n1, n2});
        }
    }

    cout << X << " " << K << '\n';
    for (int i = 0; i < K; i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}