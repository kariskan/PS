#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int p[200002], g[200002];
int Find(int x) {
	if (p[x] == -1) {
		return x;
	}
	return p[x] = Find(p[x]);
}
void Union(int a, int b) {
	p[b] = a;
	g[a] += g[b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		map<string, int> idx;
		int num = 0;
		memset(p, -1, sizeof(p));
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (idx.find(s1) == idx.end()) {
				g[num] = 1;
				idx[s1] = num++;
			}
			if (idx.find(s2) == idx.end()) {
				g[num] = 1;
				idx[s2] = num++;
			}
			int p1 = Find(idx[s1]);
			int p2 = Find(idx[s2]);
			if (p1 == -1 || p1 != p2) {
				Union(p1, p2);
			}
			cout << g[p1] << '\n';
		}
	}
}