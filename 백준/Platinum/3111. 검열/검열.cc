#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string s1, s2;
char st1[300001], st2[300001];
int st1idx, st2idx;
int len, len2;
bool ok;
bool check() {
	if (st1idx < len)return false;
	for (int i = 0; i < len; i++) {
		if (st1[st1idx - i - 1] != s1[len - i - 1])return false;
	}
	return true;
}
bool checkReverse() {
	if (st2idx < len)return false;
	for (int i = 0; i < len; i++) {
		if (st2[st2idx - i - 1] != s1[i])return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s1 >> s2;
	len = s1.length();
	len2 = s2.length();
	int idx1 = 0, idx2 = len2 - 1;
	while (idx1 <= idx2) {

		if (!ok) st1[st1idx++] = s2[idx1++];
		else st2[st2idx++] = s2[idx2--];

		if (!ok && check()) {
			ok = !ok;
			st1idx -= len;
		}
		else if (ok && checkReverse()) {
			ok = !ok;
			st2idx -= len;
		}
	}

	for (int i = st2idx - 1; i >= 0; i--) {
		st1[st1idx++] = st2[i];
		if (check()) {
			st1idx -= len;
		}
	}

	for (int i = 0; i < st1idx; i++) {
		cout << st1[i];
	}
}