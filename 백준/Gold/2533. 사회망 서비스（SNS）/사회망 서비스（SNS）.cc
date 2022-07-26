#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int dp[1000001], visit[1000001]; //최소 얼리어답터 개수
int ans;
bool go(int node) {
	if (dp[node])return dp[node];
	
	bool ret = 0;
	visit[node] = 1;

	for (auto& i : v[node]) {
		if (!visit[i]) {
			if (!go(i)) {
				ret = true;
			}
		}
	}
	if (ret)ans++;
	return dp[node] = ret;
}

int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	go(1);
	cout << ans;
}