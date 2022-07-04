#include <iostream>
using namespace std;

int n;
int a[100000], mi[100000], ma[100000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mi[0] = ma[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) {
			ma[i] = ma[i - 1] + 1;
		}
		else ma[i] = 1;
		if (a[i] <= a[i - 1]) {
			mi[i] = mi[i - 1] + 1;
		}
		else mi[i] = 1;
		ans = max(ans, max(ma[i], mi[i]));
	}
	cout << ans;
}