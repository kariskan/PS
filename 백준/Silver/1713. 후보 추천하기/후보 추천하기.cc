#include <iostream>
using namespace std;
int check[101], t[101];

int main() {
	int n, m; cin >> n >> m;

	int res = n;

	for (int i = 1; i <= m; i++) {
		int a; cin >> a;

		if (check[a]) {
			check[a]++;
		}
		else {
			if (res) { //사진 틀 남아있음
				res--;
				check[a] = 1;
				t[a] = i;
			}
			else {
				int idx, minc = 1000, mint = 1000;
				for (int j = 1; j <= 100; j++) {
					if (!check[j]) continue;
					if (minc >= check[j]) {
						if ((minc == check[j] && mint > t[j]) || minc > check[j]) {
							idx = j;
							minc = check[j];
							mint = t[j];
						}
					}
				}
				check[idx] = 0;
				t[idx] = 0;

				check[a] = 1;
				t[a] = i;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (check[i])cout << i << ' ';
	}
}