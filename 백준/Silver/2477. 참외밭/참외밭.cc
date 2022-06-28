#include <iostream>
using namespace std;

int maxX, maxY;
int inp[6][2];
int cnt[5];
int main() {
	int k;
	cin >> k;
	int t = 1;

	for (int i = 0; i < 6; i++) {
		cin >> inp[i][0] >> inp[i][1];
		if (inp[i][0] == 1 || inp[i][0] == 2)maxX = max(maxX, inp[i][1]);
		else maxY = max(maxY, inp[i][1]);
		cnt[inp[i][0]]++;
	}
	for (int i = 0; i < 6; i++) {
		if (cnt[inp[i][0]] != 1 && inp[i][0] == inp[(i + 2) % 6][0]) {
			t *= inp[(i + 1) % 6][1];
		}
	}
	cout << k * (maxX * maxY - t);
}