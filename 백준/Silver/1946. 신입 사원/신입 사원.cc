#include <iostream>
#include <algorithm>
using namespace std;
int t;
pair<int, int> a[100001];

bool compare(pair<int, int>& f, pair<int, int>& s) {
	
	return f.first < s.first;
}

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a, a + n, compare);
		int ans = 1;
		int min = a[0].second;
		for (int i = 1; i < n; i++) {
			if (min > a[i].second) {
				min = a[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}