#include <iostream>
using namespace std;
int ar[2000001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ar[a] = 1;
	}
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 1; i < (k + 1) / 2; i++) {
		if (ar[i] && ar[k - i])ans++;
	}
	cout << ans;
}