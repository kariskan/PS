#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
pair<int, int> pro[200001];
priority_queue<int> pq;
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first < p2.first;
}

int main() {
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> pro[i].first >> pro[i].second;
	}

	sort(pro + 1, pro + n + 1, compare);
	int ans = 0, idx = n;
	for (int i = n; i >= 1; i--) {
		for (; idx >= 1 && pro[idx].first == i; idx--) {
			pq.push(pro[idx].second);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}