#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

map<int, vector<int>> m;
int ans, root, parent[1000001];

void get(int node, int pre, int k) {
	if (node != root && parent[node] != parent[k] && parent[parent[node]] == parent[parent[k]])ans++;

	for (auto& i : m[node]) {
		if (i != pre) {
			get(i, node, k);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int n, k; cin >> n >> k;
		if (n == 0 && k == 0)break;

		m.clear();
		ans = 0;
		memset(parent, 0, sizeof(parent));
		cin >> root;

		vector<int> temp = { root };
		vector<int> inp, temp2;
		int last = root, tempidx = -1;

		for (int i = 0; i < n - 1; i++) {
			int a; cin >> a;
			inp.push_back(a);
		}

		for (int i = 0; i < inp.size(); i++) {
			if (last + 1 != inp[i]) {
				tempidx++;
				if (tempidx == temp.size()) {
					temp = temp2;
					temp2.clear();
					tempidx = 0;
				}
			}
			m[temp[tempidx]].push_back(inp[i]);
			parent[inp[i]] = temp[tempidx];
			temp2.push_back(inp[i]);
			last = inp[i];
		}

		get(root, 0, k);

		cout << ans << '\n';
	}
}