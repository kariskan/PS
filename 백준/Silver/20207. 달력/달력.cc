#include <iostream>
#include <algorithm>
using namespace std;

int n, ar[366];
pair<int, int> a[1000];

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	
	if (p1.first == p2.first) {
		return p1.second - p1.first < p2.second - p2.first;
	}

	return p1.first < p2.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		for (int j = a[i].first; j <= a[i].second; j++) {
			ar[j]++;
		}
	}

	sort(a, a + n);
	
	int w = 0, h = 0, ans = 0;

	for (int i = 1; i <= 365; i++) {
		if (ar[i]) {
			h = max(h, ar[i]);
			w++;
		}
		if (!ar[i] || i == 365) {
			ans += h * w;
			h = 0;
			w = 0;
		}
	}

	cout << ans;
}