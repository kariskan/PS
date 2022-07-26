#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int visit[1000001]; //최소 얼리어답터 개수
int ans;
bool go(int node) {
	
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
	return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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