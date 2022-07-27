#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> a[100000];
int n, d;
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second < p2.second;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second)swap(a[i].first, a[i].second);
	}
	cin >> d;
	sort(a, a + n, compare);
	priority_queue<int, vector<int>, greater<int>> q;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].second - a[i].first > d) {
			continue;
		}
		
		q.push(a[i].first);
		
		while (!q.empty() && a[i].second - q.top() > d) {
			q.pop();
		}

		ans = max(ans, (int)q.size());
	}
	cout << ans;
}