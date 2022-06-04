#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a = 0, b = 0;
	while (n) {
		a = a * 10 + n % 10;
		b = b * 10 + m % 10;
		n /= 10;
		m /= 10;
	}
	a < b ? cout << b : cout << a;
}