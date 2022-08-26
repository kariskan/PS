#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a[8];
vector<vector<int>> ans;
void go(vector<int> v, int idx) {
	if (v.size() == m) {
		ans.push_back(v);
		return;
	}

	for (int i = 0; i < n; i++) {
		v.push_back(a[i]);
		go(v, i + 1);
		v.pop_back();
	}
	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	go({}, 0);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (auto& i : ans) {
		for (auto& j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}