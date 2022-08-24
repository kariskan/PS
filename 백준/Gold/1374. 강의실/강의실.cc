#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, check[100001];
pair<int, int> m[100001];

int main() {

	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		m[a] = { b,c };
	}

	sort(m + 1, m + 1 + n);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		
		while (!pq.empty() && pq.top() <= m[i].first) {
			pq.pop();
		}

		pq.push(m[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}