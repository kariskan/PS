#include <iostream>
#include <queue>
using namespace std;

int n, w, l, a[1000];
queue<pair<int, int>> q; //w, l

int main() {
	cin >> n >>l >> w;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0, idx = 0;

	for (int i = 1;; i++) {

		if (idx == n && q.empty()) {
			cout << i - 1;
			break;
		}

		if (!q.empty() && i - q.front().second + 1 > l) {
			sum -= q.front().first;
			q.pop();
		}

		if (q.size() < l && sum + a[idx] <= w && idx < n) {
			q.push({ a[idx],i });
			sum += a[idx++];
		}
	}

}