#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ans;
int map[101][101];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		map[i][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					map[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] && map[j][i]) {
				ans.push_back(i);
				ans.push_back(j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans)cout << i << '\n';
}