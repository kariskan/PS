#include <iostream>
#include <string>
using namespace std;
int n, k;
int map[10][10];
int ans = 1000000000;
int visit[10];
bool check() {
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			return false;
		}
	}
	return true;
}
void run(int idx, int sum, string order) {
	if (check()) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			run(i, sum + map[idx][i], order + to_string(i));
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0)continue;
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	run(k, 0, "");
	cout << ans;
}