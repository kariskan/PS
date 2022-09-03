#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;

	int ans = -1, ansidx = -1;

	for (int i = 1; i <= n; i++) {

		int arr[5] = { 0, };

		for (int j = 0; j < 5; j++) {
			cin >> arr[j];
		}

		int seq[5] = { 0,0,1,1,1 };

		do {
			int temp = 0;
			for (int k = 0; k < 5; k++) {
				if (seq[k]) {
					temp += arr[k];
				}
			}
			temp = temp % 10;
			if (ans <= temp) {
				ans = temp;
				ansidx = i;
			}
		} while (next_permutation(seq, seq + 5));
	}

	cout << ansidx;
}