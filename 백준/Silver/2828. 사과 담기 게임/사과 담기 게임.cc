#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int now = 1;
	int j;
	cin >> j;
	int ans = 0;
	for (int i = 0; i < j; i++) {
		int num; cin >> num;
		if (num >= now && num <= now + m - 1)continue;
		else {
			if (num < now) {
				ans += now - num;
				now = num;
			}
			else {
				ans += num - m - now + 1;
				now = num - m + 1;
			}
		}
	}
	cout << ans;
}