#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000] = { 0, };
	double sum = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	for (int i = 0; i < n; i++) {
		sum += a[i] * 100.0 / m;
	}
	cout << sum / n;
}