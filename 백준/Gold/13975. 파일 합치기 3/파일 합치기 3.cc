#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int n;
int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			pq.push(num);
		}
		long long ans = 0;
		while (pq.size() != 1) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			pq.push(a + b);
			ans += a + b;
		}
		while (!pq.empty())pq.pop();
		cout << ans << '\n';
	}
}