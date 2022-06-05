#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second)return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), compare);
	int ans = 0;
	int start = 0, end = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first < end)continue;
		else {
			ans++;
			start = v[i].first;
			end = v[i].second;
		}
	}
	cout << ans;
}