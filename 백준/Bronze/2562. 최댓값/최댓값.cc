#include <iostream>
using namespace std;

int main() {
	int max = 0, idx = 0;
	for (int i = 1; i <= 9; i++) {
		int a; cin >> a;
		if (max < a) {
			max = a;
			idx = i;
		}
	}
	cout << max << "\n" << idx;
}