#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		if (!pq.empty() && pq.top() <= v[i].first) {
			pq.pop();
		}
		pq.push(v[i].second);
	}

	cout << pq.size();
}