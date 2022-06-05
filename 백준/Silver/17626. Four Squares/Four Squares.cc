#include <iostream>
using namespace std;
int ar[50001];

int main() {
	int n;
	cin >> n;
	ar[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j * j == i) {
				ar[i] = 1;
				break;
			}
			if (ar[i] == 0 || ar[i] > ar[j * j] + ar[i - j * j]) {
				ar[i] = ar[j * j] + ar[i - j * j];
			}
		}
	}
	cout << ar[n];
}