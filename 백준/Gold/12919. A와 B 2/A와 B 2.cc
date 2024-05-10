#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

string s, t;
bool flag;
void go(string now) {
	if (now == s) {
		flag = true;
		return;
	}
	if (now.length() == s.length()) {
		return;
	}
	if (flag) {
		return;
	}
	if (now.back() == 'A') {
		go(now.substr(0, now.length() - 1));
	}
	if (flag) {
		return;
	}
	if (now[0] == 'B') {
		string n = now;
		reverse(n.begin(), n.end());
		go(n.substr(0, n.length() - 1));
	}
}
int main() {
	cin >> s >> t;
	go(t);
	cout << flag;
}