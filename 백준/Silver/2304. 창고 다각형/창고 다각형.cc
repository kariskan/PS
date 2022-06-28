#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int map[1001];
int st = 1001, de;
int leftMax(int i) {
	int ret = 0;
	for (int j = i; j >= st; j--) {
		ret = max(ret, map[j]);
	}
	return ret;
}

int rightMax(int i) {
	int ret = 0;
	for (int j = i; j <= de; j++) {
		ret = max(ret, map[j]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		map[a] = b;
		st = min(st, a);
		de = max(de, a);
	}
	int ans = 0;
	for (int i = st; i <= de; i++) {
		ans += min(leftMax(i), rightMax(i));
	}
	cout << ans;
}