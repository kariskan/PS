#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100000];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);

	priority_queue<int, vector<int>, greater<int>> pq;

	int ans = 0;

	for (int i = 0; i < n; i++) {

		while (!pq.empty() && pq.top() <= arr[i].first) {
			pq.pop();
		}

		pq.push(arr[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}