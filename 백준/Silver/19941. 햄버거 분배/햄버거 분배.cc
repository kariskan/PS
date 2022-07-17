#include <iostream>
using namespace std;
int n, m;
string s;
int visit[20000];
int main() {
	cin >> n >> m >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') {
			for (int j = max(0, i - m); j <= min(n - 1, i + m); j++) {
				if (!visit[j] && s[j] == 'H') {
					visit[j] = 1;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
}