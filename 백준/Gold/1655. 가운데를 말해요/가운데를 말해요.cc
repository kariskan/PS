#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	// 1 2 -99 5
	// 5 10 7
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (maxq.size() <= minq.size()) {
			maxq.push(a);
		}
		else {
			minq.push(a);
		}

		if (!maxq.empty() && !minq.empty() && maxq.top() > minq.top()) {
			int c = maxq.top();
			int d = minq.top();
			maxq.pop();
			minq.pop();

			maxq.push(d);
			minq.push(c);
		}
		cout << maxq.top() << '\n';
	}
}