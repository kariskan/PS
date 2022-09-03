#include <iostream>
using namespace std;

int arr[4][6][3], ans, res[6][3];
int t1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int t2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

void go(int idx, int turn) {
	if (turn == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (res[i][j] != arr[idx][i][j]) {
					return;
				}
			}
		}
		ans = 1;
		return;
	}

	res[t1[turn]][0]++;
	res[t2[turn]][2]++;
	go(idx, turn + 1);
	res[t1[turn]][0]--;
	res[t2[turn]][2]--;

	res[t1[turn]][1]++;
	res[t2[turn]][1]++;
	go(idx, turn + 1);
	res[t1[turn]][1]--;
	res[t2[turn]][1]--;

	res[t1[turn]][2]++;
	res[t2[turn]][0]++;
	go(idx, turn + 1);
	res[t1[turn]][2]--;
	res[t2[turn]][0]--;
}

int main() {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> arr[i][j][k];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		ans = 0;
		go(i, 0);
		if (ans)cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}