#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w, h, n;
vector<pair<int, int>> v;
int sol(int sx1, int sy1, int sx2, int sy2) {
	if (sx1 <= w && sy1 <= h) {
		if (w - sx1 >= sx2 && h >= sy2) {
			return sx1 * sy1 + sx2 * sy2;
		}
		if (h - sy1 >= sy2 && w >= sx2) {
			return sx1 * sy1 + sx2 * sy2;
		}
	}
	if (sx2 <= w && sy2 <= h) {
		if (w - sx2 >= sx1 && h >= sy1) {
			return sx1 * sy1 + sx2 * sy2;
		}
		if (h - sy2 >= sy1 && w >= sx1) {
			return sx1 * sy1 + sx2 * sy2;
		}
	}
	return 0;
}

int main() {
	cin >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			ans = max(ans, sol(v[i].first, v[i].second, v[j].first, v[j].second));
			ans = max(ans, sol(v[i].second, v[i].first, v[j].first, v[j].second));
			ans = max(ans, sol(v[i].second, v[i].first, v[j].second, v[j].first));
			ans = max(ans, sol(v[i].first, v[i].second, v[j].second, v[j].first));
		}
	}
	cout << ans;
}