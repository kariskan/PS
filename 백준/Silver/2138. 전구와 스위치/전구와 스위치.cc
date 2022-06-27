#include <iostream>
using namespace std;
int n;
string s, t;
int ans = 1000000;
void go(int k) {
	string temp = s;
	int cnt = 0;
	if (k == 0) {
		temp[0] = temp[0] == '0' ? '1' : '0';
		temp[1] = temp[1] == '0' ? '1' : '0';
		cnt++;
	}
	for (int i = 1; i < n; i++) {
		if (t[i - 1] != temp[i - 1]) {
			temp[i - 1] = temp[i - 1] == '0' ? '1' : '0';
			temp[i] = temp[i] == '0' ? '1' : '0';
			if (i < n - 1) temp[i + 1] = temp[i + 1] == '0' ? '1' : '0';
			cnt++;
		}
	}
	if (t == temp) {
		ans = min(ans, cnt);
	}
}
int main() {
	cin >> n >> s >> t;
	go(0);
	go(1);
	if (ans == 1000000)cout << -1;
	else cout << ans;
}