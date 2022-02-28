#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1001] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int d[1001] = { 0, };
	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], d[i - j] + d[j]);
		}
	}
	cout << d[n];
}