#include <iostream>
using namespace std;

int h, w, map[502];

int leftMin(int now, int j) {
	for (int i = now - 1; i >= 0; i--) {
		if (j <= map[i])return 1;
	}
	return 0;
}

int rightMin(int now, int j) {
	for (int i = now + 1; i <= w + 1; i++) {
		if (j <= map[i])return 1;
	}
	return 0;
}

int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		cin >> map[i];
	}
	int ans = 0;
	for (int i = 1; i <= w; i++) {
		for (int j = h; j > map[i]; j--) {
			if (leftMin(i, j) && rightMin(i, j)) {
				ans++;
			}
		}
	}
	cout << ans;
}