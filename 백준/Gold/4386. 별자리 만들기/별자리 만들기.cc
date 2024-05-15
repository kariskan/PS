#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
using namespace std;

pair<double, double> inp[101];
int p[101];

double getDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool compare(pair<pair<int, int>, double>& p1, pair<pair<int, int>, double>& p2) {
	return p1.second < p2.second;
}

int Find(int x) {
	if (x == p[x]) {
		return x;
	}
	return p[x] = Find(p[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<pair<int, int>, double>> v;
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i].first >> inp[i].second;
		p[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back({ {i,j},getDistance(inp[i].first,inp[i].second,inp[j].first,inp[j].second) });
		}
	}

	sort(v.begin(), v.end(), compare);

	double answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (Find(v[i].first.first) != Find(v[i].first.second)) {
			Union(v[i].first.first, v[i].first.second);
			answer += v[i].second;
		}
	}
	cout << answer;
}