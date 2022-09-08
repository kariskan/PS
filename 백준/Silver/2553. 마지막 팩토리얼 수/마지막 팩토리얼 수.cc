#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	long long a = 1;
	for (int i = 2; i <= n; i++) {
		a *= i;
		while (a % 10 == 0) {
			a /= 10;
		}
		a = a % 10000000;
	}
	cout << a % 10;
}