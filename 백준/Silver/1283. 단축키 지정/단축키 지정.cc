#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int toIndex(char a) {
	if (a >= 'a' && a <= 'z') {
		return a - 'a';
	}
	return a - 'A';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, vis[26] = { 0, };

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);

		if (!vis[toIndex(s[0])]) {
			vis[toIndex(s[0])] = 1;
			cout << '[' << s[0] << ']' << s.substr(1) << '\n';
			continue;
		}
		bool flag = false;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ' && !vis[toIndex(s[j + 1])]) {
				vis[toIndex(s[j + 1])] = 1;
				cout << s.substr(0, j + 1) << '[' << s[j + 1] << ']' << s.substr(j + 2) << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			for (int j = 0; j < s.length(); j++) {
				if (s[j] != ' ' && !vis[toIndex(s[j])]) {
					vis[toIndex(s[j])] = 1;
					cout << s.substr(0, j) << '[' << s[j] << ']' << s.substr(j + 1) << '\n';
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			cout << s << '\n';
		}
	}
}