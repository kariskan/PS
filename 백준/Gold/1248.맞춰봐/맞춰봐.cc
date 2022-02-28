#include <iostream>
#include <vector>
using namespace std;
int board[11][11];
int n;
vector<int> v;
int b;
bool check(int s) {
	int sum = 0;
	for (int i = s; i >= 0; i--) {
		sum += v[i];
		if (board[i][s] == 0 && sum != 0)return false;
		else if (board[i][s] == 1 && sum <= 0)return false;
		else if (board[i][s] == -1 && sum >= 0)return false;
	}
	return true;
}
void run(int index) {
	if (index == n) {
		b = 1;
		return;
	}
	if (board[index][index] == 0) {
		v[index] = 0;
		if (check(index)) run(index + 1);
		if (b)return;
	}
	for (int i = 1; i <= 10; i++) {
		v[index] = i * board[index][index];
		if (check(index))run(index + 1);
		if (b)return;
	}
}
int main() {
	cin >> n;
	string s;
	cin >> s;
	int len = s.length();
	int cnt = 0;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[cnt] == '-')board[i][j] = -1;
			else if (s[cnt] == '0')board[i][j] = 0;
			else board[i][j] = 1;
			cnt++;
		}
	}
	run(0);
	for (int i = 0; i < n; i++)cout << v[i] << " ";
}