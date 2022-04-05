#include <iostream>
using namespace std;
string s, p;
int main() {
	cin >> s >> p;
	int sLen = s.length();
	int pLen = p.length();
	if (sLen >= pLen) {
		int pHash = 0, sHash = 0;
		for (int i = 0; i < pLen; i++) {
			pHash = (pHash * 256 + p[i]) % 127;
		}
		for (int i = 0; i < pLen; i++) {
			sHash = (sHash * 256 + s[i]) % 127;
		}
		int dup = 1;
		for (int i = 0; i < pLen - 1; i++) {
			dup = (dup * 256) % 127;
		}
		for (int i = 0; i <= sLen - pLen; i++) {
			if (pHash == sHash) {
				if (p == s.substr(i, pLen)) {
					cout << 1;
					return 0;
				}
			}
			if (i + pLen < sLen) {
				sHash -= (s[i] * dup) % 127;
				sHash = (sHash + 127) % 127;
				sHash = ((sHash * 256) % 127 + s[i + pLen]) % 127;
			}
		}
	}
	cout << 0;
}