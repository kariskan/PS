#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}
vector<pair<int, int>> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	int ans[1001] = { 0, };
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		int idx = v[i].first;
		while (idx > 0 && ans[idx]) {
			idx--;
		}
		if (idx > 0)ans[idx] = v[i].second;
	}
	int answer = 0;
	for (int i = 0; i <= 1000; i++)answer += ans[i];
	cout << answer;
}