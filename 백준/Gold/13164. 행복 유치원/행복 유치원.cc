#include <iostream>
#include <queue>
using namespace std;
int a[300000];
int main() {
	priority_queue<int> q;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i)q.push(a[i] - a[i - 1]);
	}
	m--;
	while (m--) {
		q.pop();
	}
	long long ans = 0;
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}
	cout << ans;
}