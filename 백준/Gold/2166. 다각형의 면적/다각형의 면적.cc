#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<pair<double, double>> v;

double calc(int x1, int x2, int x3, int y1, int y2, int y3) {
	pair<double, double> vector1 = { x2 - x1,y2 - y1 };
	pair<double, double> vector2 = { x3 - x1,y3 - y1 };
	return (vector1.first * vector2.second - vector1.second * vector2.first) / 2;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	double ans = 0;
	for (int i = 2; i < n; i++) {
		ans += calc(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);
	}
	ans = abs(round(ans * 10) / 10.0);
	cout << fixed;
	cout.precision(1);
	cout << ans;
}