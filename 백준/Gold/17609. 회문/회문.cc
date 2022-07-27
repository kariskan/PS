#include <iostream>
using namespace std;
int n;

int pal(string s, int cnt) {
	if (cnt == 2)return 2;
	int left = 0, right = s.length() - 1;
	while (left < right) {
		if (s[left] == s[right]) {
			left++;
			right--;
		}
		else {
			if (pal(s.substr(left, right - left), cnt + 1) == 0 
				|| pal(s.substr(left + 1, right - left), cnt + 1) == 0) {
				return 1;
			}
			else return 2;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int p = pal(s, 0);
		if (p == 0)cout << 0 << '\n';
		else if (p == 1)cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}