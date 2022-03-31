#include <iostream>
using namespace std;
int xs, ys, xe, ye;
pair<pair<int, int>,pair<int,int>> tp[3];
int visit[3];
long long ans = 2000000000;
long long getDis(pair<long long, long long> p1, pair<long long, long long> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
void dfs(int x, int y, long long dis) {
	ans = min(ans, dis + getDis({ x,y }, { xe,ye }));
	for (int i = 0; i < 3; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(tp[i].second.first, tp[i].second.second, dis + getDis({ x,y }, {tp[i].first.first,tp[i].first.second}) + 10);
			dfs(tp[i].first.first, tp[i].first.second, dis + getDis({ x,y }, { tp[i].second.first,tp[i].second.second}) + 10);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> xs >> ys >> xe >> ye;
	for (int i = 0; i < 3; i++) {
		cin >> tp[i].first.first >> tp[i].first.second >> tp[i].second.first >> tp[i].second.second;
	}
	dfs(xs, ys, 0);
	cout << ans;
}