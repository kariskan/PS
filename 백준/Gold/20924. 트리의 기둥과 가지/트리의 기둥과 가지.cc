#include <iostream>
#include <vector>
using namespace std;

int n, r, g;
vector<vector<pair<int, int>>> v;

void findG(int node, int pre) {
	if ((node == r && v[node].size() > 1 ) || v[node].size() > 2) {
		g = node;
		return;
	}

	g = node;

	for (auto& i : v[node]) {
		if (i.first != pre) {
			findG(i.first, node);
			if (g != 0)return;
		}
	}
}

int getgi(int node, int pre) {
	if (node == g)return 0;

	for (auto& i : v[node]) {
		if (i.first != pre) {
			return getgi(i.first, node) + i.second;
		}
	}
}

int getga(int node, int pre, bool ok) {

	if (node == g) {
		ok = true;
	}

	int ret = 0;

	for (auto& i : v[node]) {
		if (i.first != pre) {
			if (ok) {
				ret = max(ret, getga(i.first, node, ok) + i.second);
			}
			else ret = max(ret, getga(i.first, node, ok));
		}
	}

	return ret;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r;

	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	if (v[r].size() > 1) g = r;
	else findG(r, 0);
	cout << getgi(r, 0) << ' ';
	cout << getga(r, 0, false);
}