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

bool isPal(string s) {
	string s2 = s;
	reverse(s2.begin(), s2.end());
	return s == s2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	for (int len = (int)s.length();; len++) {
		string n = s;
		int idx = len - (int)s.length() - 1;
		while (n.length() != len) {
			n += s[idx--];
		}
		if (isPal(n)) {
			cout << len;
			return 0;
		}
	}
}