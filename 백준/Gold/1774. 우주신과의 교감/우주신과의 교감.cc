#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
pair<int, int> coor[1001];
int parent[1001];
vector<pair<double, pair<int, int>>> v;
double getdis(int x1, int y1, int x2, int y2) {
	double xx = pow(x1 - x2, 2);
	double yy = pow(y1 - y2, 2);
	return sqrt(xx + yy);
}
int Find(int x) {
	if (parent[x] == x)return x;
	else return Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a > b)parent[a] = b;
	else parent[b] = a;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> coor[i].first >> coor[i].second;
	}

	for (int i = 1; i <= n; i++) {
		if (!parent[i])parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (Find(a) != Find(b)) {
			Union(a, b);
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back({ getdis(coor[i].first, coor[i].second, coor[j].first, coor[j].second) ,{i,j}});
		}
	}
	sort(v.begin(), v.end());

	double ans = 0;

	for (int i = 0; i < v.size(); i++) {
		if (Find(v[i].second.first) != Find(v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	/*ans *= 100;
	ans = round(ans);
	ans /= 100;*/

	cout << fixed;
	cout.precision(2);
	cout << ans;
}