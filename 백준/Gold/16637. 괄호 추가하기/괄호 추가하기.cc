#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int ans = INT_MIN;
int n; string s;
int cal(int a, int b, char op) {
	int res = a;
	switch (op) {
	case '+': res += b; break;
	case '*': res *= b; break;
	case '-': res -= b; break;
	}
	return res;
}
void run(int index, int val) {
	if (index > n - 1) {
		ans = max(ans, val);
		return;
	}
	char op = index == 0 ? '+' : s[index - 1];
	if (index + 2 < n) {
		int temp = cal(s[index] - '0', s[index + 2] - '0', s[index + 1]);
		run(index + 4, cal(val, temp, op));
	}
	run(index + 2, cal(val, s[index] - '0', op));
}

int main() {
	cin >> n;
	cin >> s;
	run(0, 0);
	cout << ans;
}