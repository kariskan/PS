#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int, int> p[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < p[i].first)ans = p[i].first + p[i].second;
		else ans += p[i].second;
	}
	cout << ans;
}