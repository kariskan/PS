#include <iostream>
using namespace std;
int n, k, ans;
int map[8], visit[8];
void go(int sum, int cnt) {
	if (sum < 500)return;
	if (cnt == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			go(sum + map[i] - k, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	go(500, 0);
	cout << ans;
}