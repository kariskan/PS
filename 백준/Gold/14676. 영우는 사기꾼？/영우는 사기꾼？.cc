#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, inp[100001], cnt[100001];

int main() {
	cin >> n >> m >> k;
	vector<vector<int>> info(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		info[a].push_back(b);
		inp[b]++;
	}

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			if (inp[b] != 0) {
				cout << "Lier!";
				return 0;
			}
			cnt[b]++;
			if (cnt[b] == 1) {
				for (auto& j : info[b]) {
					if (inp[j]) inp[j]--;
				}
			}
		}
		else {
			if (!cnt[b]) {
				cout << "Lier!";
				return 0;
			}
			cnt[b]--;
			if (cnt[b] == 0) {
				for (auto& j : info[b]) {
					inp[j]++;
				}
			}
		}
	}

	cout << "King-God-Emperor";
}