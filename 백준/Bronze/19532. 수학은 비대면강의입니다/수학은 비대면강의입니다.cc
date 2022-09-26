#include <iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	
	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (x * a + y * b == c && x * d + y * e == f) {
				cout << x << ' ' << y;
				return 0;
			}
		}
	}
}