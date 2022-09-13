#include <iostream>
using namespace std;

int n, a[15];

int main() {
	cin >> n;
	for (int i = 1; i <= 14; i++) {
		cin >> a[i];
	}

	int money = n, stock = 0;

	for (int i = 1; i <= 14; i++) {
		stock += money / a[i];
		money -= (money / a[i]) * a[i];
	}

	int ans1 = money + stock * a[14];
	money = n, stock = 0;

	for (int i = 4; i <= 14; i++) {
		int in = 1, de = 1;
		for (int j = i; j >= i - 2; j--) {
			if (a[j] >= a[j - 1]) {
				de = 0;
			}
			if (a[j] <= a[j - 1]) {
				in = 0;
			}
		}

		if (in) {
			money += stock * a[i];
			stock = 0;
		}
		else if (de) {
			stock += money / a[i];
			money -= (money / a[i]) * a[i];
		}
	}

	int ans2 = money + a[14] * stock;
	if (ans1 > ans2) cout << "BNP";
	else if (ans1 == ans2)cout << "SAMESAME";
	else cout << "TIMING";
}