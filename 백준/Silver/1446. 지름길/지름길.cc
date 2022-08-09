#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, d;
int ans = 0;
vector<pair<pair<int, int>, int>> v;
void go(int idx, int now, int sum) {
	ans = min(ans, sum + d - now);

	for (int i = idx; i < v.size(); i++) {
		int source = v[i].first.first;
		int des = v[i].first.second;
		int cost = v[i].second;

		if (des > d || source < now)continue;
		go(i + 1, des, sum + cost + source - now);
	}
}

int main() {
	cin >> n >> d;
	ans = d;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > d || b - a < c)continue;
		v.push_back({ {a,b},c });
	}

	sort(v.begin(), v.end());

	go(0, 0, 0);

	cout << ans;
}