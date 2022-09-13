#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, k;
set<long long> visit;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<pair<long long, long long>> q; //샘터의 위치, 현재 위치

	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		q.push({ a,a });
		visit.insert(a);
	}

	long long ans = 0;

	while (!q.empty() && k) {
		long long a = q.front().first;
		long long b = q.front().second;
		q.pop();

		if (a != b) {
			ans += abs(a - b);
			k--;
		}

		if (k == 0)break;

		if (!visit.count(b - 1)) {
			visit.insert(b - 1);
			q.push({ a,b - 1 });
		}
		if (!visit.count(b + 1)) {
			visit.insert(b + 1);
			q.push({ a,b + 1 });
		}
	}

	cout << ans;
}