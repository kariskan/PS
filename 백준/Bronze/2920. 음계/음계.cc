#include <iostream>
using namespace std;

int main() {
	int a = 0, d = 0;
	for (int i = 0; i < 8; i++) {
		int n;
		cin >> n;
		if (n == i + 1) {
			a = 1;
		}
		else if (n == 8 - i) {
			d = 1;
		}
		else {
			a = 1; d = 1;
		}
	}
	if (a && d)cout << "mixed";
	else if (a)cout << "ascending";
	else cout << "descending";
}