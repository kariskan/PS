#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int parent[101];
int n;
pair<double ,double> coor[101];
vector<pair<double, pair<int, int>>> v;

double getDis(pair<double, double> x, pair<double, double> y) {
	return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> coor[i].first >> coor[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back({ getDis(coor[i],coor[j]),{i,j} });
		}
	}
	sort(v.begin(), v.end());
	double ans = 0;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (getParent(v[i].second.first) != getParent(v[i].second.second)) {
			ans += v[i].first;
			Union(v[i].second.first, v[i].second.second);
		}
	}
	cout << ans;
}