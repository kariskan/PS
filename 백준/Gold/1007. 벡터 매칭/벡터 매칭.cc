#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
pair<int, int> v[20];
int visit[20];
double ans = 100000000000000000;
double calc() {
	double resx = 0, resy = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i]) {
			resx -= v[i].first;
			resy -= v[i].second;
		}
		else {
			resx += v[i].first;
			resy += v[i].second;
		}
	}
	return sqrt(resx * resx + resy * resy);
}
void run(int now, int cnt) {
	if (cnt == n / 2) {
		ans = min(ans, calc());
	}

	for (int i = now; i < n; i++) {
		visit[i] = 1;
		run(i + 1, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		ans = 100000000000000000;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		run(0, 0);
		printf("%lf\n", ans);
	}
}