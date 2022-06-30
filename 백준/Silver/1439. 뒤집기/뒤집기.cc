#include <iostream>
using namespace std;

string s;
int main() {
	cin >> s;
	int zeroCnt = 0, oneCnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s[i] == '0')zeroCnt++;
			else oneCnt++;
			continue;
		}
		if (s[i - 1] == s[i]) {
			continue;
		}
		if (s[i] == '0')zeroCnt++;
		else oneCnt++;
	}
	if (zeroCnt < oneCnt)cout << zeroCnt;
	else cout << oneCnt;
}