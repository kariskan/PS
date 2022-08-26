#include <iostream>
#include <vector>
using namespace std;

int k;
int a[2000];
vector<vector<int>> ans(11);

void go(int left, int right, int h) {
	if (left > right) return;

	int mid = (left + right) / 2;
	ans[h].push_back(a[mid]);

	go(left, mid - 1, h + 1);
	go(mid + 1, right, h + 1);

}

int main() {
	cin >> k;

	for (int i = 1; i < (1 << k); i++) {
		cin >> a[i];
	}

	go(1, (1 << k) - 1, 1);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}
}