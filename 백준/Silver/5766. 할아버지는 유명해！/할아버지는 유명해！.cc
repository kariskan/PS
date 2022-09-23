#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	while (1) {
		int n, m; cin >> n >> m;
		if (!n && !m) break;

		map<int, int> ma;

		vector<int> v;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a; cin >> a;
				ma[a]++;
			}
		}

		for (auto& i : ma) {
			v.push_back(i.second);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		vector<int> ans;

		for (auto& i : ma) {
			if (i.second == v[v.size() - 2]) {
				ans.push_back(i.first);
			}
		}

		sort(ans.begin(), ans.end());

		for (auto& i : ans) {
			cout << i << ' ';
		}

		cout << '\n';
	}
}