#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> inp[100000];
int pc[100000], ans;

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<int, vector<int>, greater<int>> rest;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inp[i].first >> inp[i].second;
		rest.push(i);
	}

	sort(inp, inp + n);

	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top().first < inp[i].first) {
			rest.push(pq.top().second);
			pq.pop();
		}

		pc[rest.top()]++;
		pq.push({ inp[i].second,rest.top() });
		rest.pop();
		ans = max(ans, (int)pq.size());
	}

	cout << ans << '\n';

	for (int i = 0; i < ans; i++) {
		cout << pc[i] << ' ';
	}
}