#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <vector<int>> v(100001);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0 && v[i].size() > 1)ans += v[i][j + 1] - v[i][j];
			else if (j == v[i].size() - 1 && v[i].size() > 1)ans += v[i][j] - v[i][j - 1];
			else ans += min(abs(v[i][j] - v[i][j - 1]), abs(v[i][j + 1] - v[i][j]));
		}
	}

	cout << ans;
}