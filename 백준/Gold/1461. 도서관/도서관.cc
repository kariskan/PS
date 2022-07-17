#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> mi, pl;
bool compare(int& a, int& b) {
	return a > b;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num < 0)mi.push_back(num);
		else pl.push_back(num);
	}
	sort(mi.begin(), mi.end(), compare);
	sort(pl.begin(), pl.end());
	int ans = 0;
	if (!mi.empty() && (pl.empty() || abs(mi[mi.size() - 1]) > pl[pl.size() - 1])) {
		ans += abs(mi[mi.size() - 1]);
		for (int i = 0; i < m; i++) {
			mi.pop_back();
			if (mi.empty())break;
		}
	}
	else if (!pl.empty() && (mi.empty() || abs(mi[mi.size() - 1]) < pl[pl.size() - 1])) {
		ans += pl[pl.size() - 1];
		for (int i = 0; i < m; i++) {
			pl.pop_back();
			if (pl.empty())break;
		}
	}
	while(!mi.empty()) {
		ans += abs(mi[mi.size() - 1]) * 2;
		for (int j = 0; j < m; j++) {
			mi.pop_back();
			if (mi.empty())break;
		}
	}

	while(!pl.empty()) {
		ans += pl[pl.size() - 1] * 2;
		for (int j = 0; j < m; j++) {
			pl.pop_back();
			if (pl.empty())break;
		}
	}
	cout << ans;
}