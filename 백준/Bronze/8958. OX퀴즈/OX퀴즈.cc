#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int a[80] = { 0, };
		int ans = 0;
		if (s[0] == 'O') {
			a[0] = 1;
			ans++;
		}
		for (int j = 1; j < s.length(); j++) {
			if (s[j] == 'O') {
				a[j] = a[j - 1] + 1;
				ans += a[j];
			}
		}
		cout << ans << "\n";
	}
}