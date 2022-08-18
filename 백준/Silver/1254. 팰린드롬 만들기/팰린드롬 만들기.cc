#include <iostream>
using namespace std;

string s;

int getP(int l, int r) {

	int left = l, right = r;
	while (left <= right) {
		if (s[left] != s[right]) return 0;
		left++;
		right--;
	}

	return r - l + 1;
}

int main() {
	cin >> s;
	int ans = s.length() * 2;
		for (int i = 0; i < s.length(); i++) {
		ans = min(ans, (int)s.length() * 2 - getP(i, s.length() - 1));
	}

	cout << ans;
}