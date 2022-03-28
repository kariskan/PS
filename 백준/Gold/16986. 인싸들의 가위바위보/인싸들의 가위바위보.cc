#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10][10];
int p[4][21];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 20; j++) {
			if (i == 1)p[i][j] = j;
			else cin >> p[i][j];
		}
	}
	do {
		int index[4] = { 0,1,1,1 };
		int cnt[4] = { 0,0,0,0 };
		int first = 1, second = 2, third = 3;
		while (1) {
			if (first > second)swap(first, second);
			if (first == 1 && index[1] > n)break;
			if (index[first] > 20 || index[second] > 20)break;
			int p1 = p[first][index[first]++];
			int p2 = p[second][index[second]++];
			
			if (a[p1][p2] == 2) {
				cnt[first]++;
				swap(second, third);
				if (cnt[first] == k)break;
			}
			else {
				cnt[second]++;
				swap(first, third);
				if (cnt[second] == k)break;
			}
		}
		if (cnt[1] >= k) {
			cout << 1;
			return 0;
		}
	} while (next_permutation(p[1] + 1, p[1] + 1 + n));
	cout << 0;
}