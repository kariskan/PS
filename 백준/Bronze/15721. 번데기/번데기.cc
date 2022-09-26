#include <iostream>
using namespace std;

int a, t, k;

int main() {
	cin >> a >> t >> k;

	int place = 0;

	for (int i = 1;; i++) { //회차
		for (int j = 1; j <= 4 + (i + 1) * 2; j++) {
			if (j <= 4) {
				if (j % 2 != k) {
					t--;
				}
			}
			else {
				if (j <= 5 + i) { //뻔
					if (k == 0) {
						t--;
					}
				}
				else { //데기
					if (k == 1) {
						t--;
					}
				}
			}
			if (t == 0) {
				cout << place;
				return 0;
			}
			place = (place + 1) % a;
		}
	}
}