#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

set<int> se;
vector<vector<int>> v;
int visit[100001], in[100001];
bool ok;

void go(int node, int pre) {
	for (auto& i : v[node]) {
		if (i != pre) {
			if (visit[i]) {
				ok = false;
				return;
			}
			visit[i] = 1;
			go(i, node);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	while (1) {
		v.clear();
		v.resize(100001);
		memset(visit, 0, sizeof(visit));
		memset(in, 0, sizeof(in));
		se.clear();
		int a, b;
		ok = true;
		int root = 0;
		while (1) {
			cin >> a >> b;
			if (a < 0 && b < 0) {
				return 0;
			}
			if (a == 0 && b == 0) {
				break;
			}

			v[a].push_back(b);
			se.insert(a);
			se.insert(b);
			in[b]++;
		}

		for (auto& i : se) {
			if (in[i] == 0) {
				if (root != 0)ok = false;
				else root = i;
			}
			else if (in[i] > 1) {
				ok = false;
			}
		}

		if (root == 0 && !se.empty()) ok = false;

		if (ok) {
			visit[root] = 1;
			go(root, -1);
		}

		for (auto& i : se) {
			if (!visit[i]) {
				ok = false;
				break;
			}
		}

		if (ok) cout << "Case " << tc++ << " is a tree.\n";
		else cout << "Case " << tc++ << " is not a tree.\n";
	}
}