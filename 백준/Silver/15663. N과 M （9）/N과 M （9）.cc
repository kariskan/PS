#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> ans;
int visit[8];
void run(int cnt, vector<int> temp) {
	if (cnt == m) {
		ans.push_back(temp);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			temp.push_back(v[i]);
			run(cnt + 1, temp);
			temp.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	run(0, {});
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}