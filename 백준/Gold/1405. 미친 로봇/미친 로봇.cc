#include <iostream>
#include <cmath>
using namespace std;

int n;
double a[4];
int visit[30][30];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
double ans;
void go(double rate, int i, int j, int c) {
	if (c == n) {
		ans += rate;
		return;
	}
	for (int k = 0; k < 4; k++) {
		if (a[k]) {
			int nx = i + x[k];
			int ny = j + y[k];
			if (!visit[nx][ny]) {
				visit[nx][ny] = 1;
				go(rate * a[k], nx, ny, c + 1);
				visit[nx][ny] = 0;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		int num; cin >> num;
		a[i] = (double)num / 100;
	}
	visit[15][15] = 1;
	go(1, 15, 15, 0);
	cout << fixed;
	cout.precision(9);
	cout << ans;
}