#include <iostream>
#include <cmath>
using namespace std;

long long arr[1000000] = { 0, };

long long gcd(long long a, long long b) {
	if (a == 0)return b;
	return gcd(b % a, a);
}
int arrcount = 0;
void Prime(int m) {
	for (int i = 1; i <= sqrt(m); i++) {
		if (m % i == 0) {
			if (i == m / i)arr[arrcount++] = i;
			else {
				arr[arrcount++] = i;
				arr[arrcount++] = m / i;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 300000000;
	Prime(m);
	long long ans1, ans2;
	for (int i = 0; i < arrcount; i++) {
		for (int j = i; j < arrcount; j++) {
			long long p1 = arr[i] * arr[j];
			if (gcd(arr[i], arr[j]) == n && p1 / gcd(arr[i], arr[j]) == m) {
				if (ans > arr[i] + arr[j]) {
					ans = arr[i] + arr[j];
					ans1 = arr[i];
					ans2 = arr[j];
				}
			}
		}
	}
	if (ans1 > ans2)swap(ans1, ans2);
	cout << ans1 << " " << ans2;
}