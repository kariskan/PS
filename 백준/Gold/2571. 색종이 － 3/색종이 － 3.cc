#include <iostream>
using namespace std;
int visit[101][101];
int s[101][101];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				if (!visit[j][k]) {
					visit[j][k] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visit[i][j]) {
				s[i][j] = s[i][j - 1] + 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visit[i][j]) {
				int h = 1;
				int w = s[i][j];
				for (int k = i; k >= 0; k--, h++) {
					if (!s[k][j])break;
					w = min(w, s[k][j]);
					ans = max(ans, h * w);
				}
			}
		}
	}
	cout << ans;
}