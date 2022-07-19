#include <iostream>
using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;
	string t = s;
	//빨간색 오른쪽 옮기기
	int idx = n - 1;
	while (idx >= 0 && t[idx] == 'R') {
		idx--;
	}
	int ans1 = 0;
	for (int i = idx; i >= 0; i--) {
		if (t[i] == 'R') {
			ans1++;
		}
	}
	//빨간색 왼쪽 옮기기
	t = s;
	idx = 0;
	while (idx < n && t[idx] == 'R') {
		idx++;
	}
	int ans2 = 0;
	for (int i = idx; i < t.length(); i++) {
		if (t[i] == 'R') {
			ans2++;
		}
	}
	ans1 = min(ans1, ans2);
	//파란색 옮기기
	t = s;
	idx = n - 1;
	while (idx >= 0 && t[idx] == 'B') {
		idx--;
	}
	ans2 = 0;
	for (int i = idx; i >= 0; i--) {
		if (t[i] == 'B') {
			ans2++;
		}
	}
	ans1 = min(ans1, ans2);
	//파란색 왼쪽 옮기기
	t = s;
	idx = 0;
	while (idx < n && t[idx] == 'B') {
		idx++;
	}
	ans2 = 0;
	for (int i = idx; i < t.length(); i++) {
		if (t[i] == 'B') {
			ans2++;
		}
	}
	cout << min(ans1, ans2);
}