#include <iostream>
using namespace std;

int main() {
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	int ans = 0;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		if ((a >= x && a <= x + w && b >= y && b <= y + h)
			|| ((a - x) * (a - x) + (b - y - h / 2) * (b - y - h / 2) <= (h / 2) * (h / 2))
			|| ((a - x - w) * (a - x - w) + (b - y - h / 2) * (b - y - h / 2) <= (h / 2) * (h / 2))) {
			ans++;
		}
	}
	cout << ans;
}