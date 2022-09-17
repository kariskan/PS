#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(26);

int main() {
	int t; cin >> t;
	while (t--) {
		v.clear();
		v.resize(26);
		string s; cin >> s;
		int n; cin >> n;

		for (int i = 0; i < s.length(); i++) {
			v[s[i] - 'a'].push_back(i);
		}

		int ans1 = -1, ans2 = -1;

		for (int i = 0; i < 26; i++) {
			if (v[i].size() < n) continue;
			int k = 0;

			while (k + n - 1 < v[i].size()) {
				if (ans1 == -1 || ans1 > v[i][k + n - 1] - v[i][k] + 1) {
					ans1 = v[i][k + n - 1] - v[i][k] + 1;
				}

				if (ans2 == -1 || ans2 < v[i][k + n - 1] - v[i][k] + 1) {
					ans2 = v[i][k + n - 1] - v[i][k] + 1;
				}

				k++;
			}
		}

		if (ans1 == -1 || ans2 == -1) {
			cout << -1 << '\n';
		}
		else cout << ans1 << ' ' << ans2 << '\n';
	}
}