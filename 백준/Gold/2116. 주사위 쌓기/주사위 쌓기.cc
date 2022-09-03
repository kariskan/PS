#include <iostream>
using namespace std;

int n, arr[10000][6];
int no[6] = { 5,3,4,1,2,0 };

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int k = 0; k < 6; k++) {
		int up = arr[0][k];
		int temp = 0;

		for (int i = 0; i < 6; i++) {
			if (i != k && i != no[k]) {
				temp = max(temp, arr[0][i]);
			}
		}

		for (int i = 1; i < n; i++) {
			int findBottomIdx = 0;
			for (int j = 0; j < 6; j++) {
				if (up == arr[i][j]) {
					findBottomIdx = j;
					break;
				}
			}
			int tempp = 0;
			for (int j = 0; j < 6; j++) {
				if (j != findBottomIdx && j != no[findBottomIdx]) {
					tempp = max(tempp, arr[i][j]);
				}
			}
			temp += tempp;
			up = arr[i][no[findBottomIdx]];
		}
		ans = max(ans, temp);
	}

	cout << ans;
}