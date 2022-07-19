#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int t[10000];
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	sort(t, t + n);
	int tc = 0;
	int total = c;
	int money = a;
	for (int i = n - 1; i >= 0; i--) {
		if (total * (money + b) < (total + t[i]) * (money)) {
			total += t[i];
			tc++;
			money += b;
		}
	}
	cout << total / money;
}