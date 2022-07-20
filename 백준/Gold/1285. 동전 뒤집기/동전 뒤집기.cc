#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> a(20, vector<char>(20));

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 1000000000;
	for (int i = 0; i < (1 << n); i++) {
		vector<vector<char>> t = a;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++) {
					if (t[j][k] == 'H')t[j][k] = 'T';
					else t[j][k] = 'H';
				}
			}
		}
		int tot = 0;
		for (int i1 = 0; i1 < n; i1++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (t[j][i1] == 'T')cnt++;
			}
			if (cnt > n - cnt) {
				tot += n - cnt;
			}
			else tot += cnt;
		}
		ans = min(ans, tot);
	}
	cout << ans;
}