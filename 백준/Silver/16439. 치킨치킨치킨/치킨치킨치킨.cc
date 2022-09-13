#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[30][30];
int main() {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> v(k - 3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	int ans = 0;
	do {
		int t = 0;
		for (int i = 0; i < n; i++) {
			int tmax = 0;
			for (int j = 0; j < k; j++) {
				if (tmax < a[i][j] && v[j]) {
					tmax = a[i][j];
				}
			}
			t += tmax;
		}
		ans = max(ans, t);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
}