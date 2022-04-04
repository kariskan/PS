#include <iostream>
#include <stack>
using namespace std;
int leftBig[1000001], rightBig[1000001], leftSmall[1000001], rightSmall[1000001], a[1000001];
int n;
long long sol(long long n) {
	return n * (n + 1) / 2;
}
void runRight() {
	stack<pair<int, int>> smallBig, smallSmall;
	smallBig.push({ 1,a[1] });
	smallSmall.push({ 1,a[1] });
	for (int i = 2; i <= n; i++) {
		while (!smallBig.empty() && a[i] >= smallBig.top().second) {
			rightBig[smallBig.top().first] = i;
			smallBig.pop();
		}
		smallBig.push({ i,a[i] });
		while (!smallSmall.empty() && a[i] <= smallSmall.top().second) {
			rightSmall[smallSmall.top().first] = i;
			smallSmall.pop();
		}
		smallSmall.push({ i,a[i] });
	}
}
void runLeft() {
	stack<pair<int, int>> smallBig, smallSmall;
	smallBig.push({ n,a[n] });
	smallSmall.push({ n,a[n] });
	for (int i = n - 1; i >= 1; i--) {
		while (!smallBig.empty() && a[i] > smallBig.top().second) {
			leftBig[smallBig.top().first] = i;
			smallBig.pop();
		}
		smallBig.push({ i,a[i] });
		while (!smallSmall.empty() && a[i] < smallSmall.top().second) {
			leftSmall[smallSmall.top().first] = i;
			smallSmall.pop();
		}
		smallSmall.push({ i,a[i] });
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		rightBig[i] = rightSmall[i] = n + 1;
	}
	runRight();
	runLeft();
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = min(i, leftBig[i] + 1);
		int r = max(i, rightBig[i] - 1);
		long long len = r - l + 1;
		ans += (sol(len) - sol(r - i) - sol(i - l)) * a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = min(i, leftSmall[i] + 1);
		int r = max(i, rightSmall[i] - 1);
		long long len = r - l + 1;
		ans -= (sol(len) - sol(r - i) - sol(i - l)) * a[i];
	}
	cout << ans;
}