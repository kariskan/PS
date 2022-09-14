#include <iostream>
using namespace std;

int a[100001], mul[100001];

int main() {
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mul[i] = mul[i - 1] + a[i];
	}

	long long ans = 0;

	for (int i = 2; i <= n; i++) {
		ans += mul[i - 1] * a[i];
	}

	cout << ans;
}