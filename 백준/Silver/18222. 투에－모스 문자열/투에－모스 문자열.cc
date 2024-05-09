#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int main() {
	long long k;
	cin >> k;

	int cnt = 0;
	while (k > 1) {
		for (long long i = 1;; i *= 2) {
			if (k - i <= 0) {
				k = k - i / 2;
				cnt++;
				break;
			}
		}
	}

	if (cnt % 2 == 0) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}