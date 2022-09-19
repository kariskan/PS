#include <iostream>
using namespace std;

int arr[100001][21], visit[2000000];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			arr[b][c] = 1;
		}
		else if (a == 2) {
			cin >> c;
			arr[b][c] = 0;
		}
		else if (a == 3) {
			for (int j = 20; j >= 2; j--) {
				arr[b][j] = arr[b][j - 1];
			}
			arr[b][1] = 0;
		}
		else {
			for (int j = 1; j < 20; j++) {
				arr[b][j] = arr[b][j + 1];
			}
			arr[b][20] = 0;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j <= 20; j++) {
			if (arr[i][j]) {
				k += (1 << j);
			}
		}
		
		if (!visit[k]) {
			visit[k] = 1;
			ans++;
		}
	}

	cout << ans;
}