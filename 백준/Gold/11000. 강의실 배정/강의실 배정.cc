#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair <int, int> p[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	pq.push(p[0].second);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= p[i].first) {
			pq.pop();
			pq.push(p[i].second);
		}
		else {
			pq.push(p[i].second);
		}
	}
	cout << pq.size();
}