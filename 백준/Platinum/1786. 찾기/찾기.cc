#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t, p;
int fail[1000001];
int main() {
	getline(cin, t);
	getline(cin, p);
	int tLen = t.length();
	int pLen = p.length();
	int j = 0;
	for (int i = 1; i < pLen; i++) {
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) {
			fail[i] = j + 1;
			j++;
		}
		else fail[i] = 0;
	}
	vector<int> v;
	if (tLen >= pLen) {
		int i = 0, j = 0;
		for (int i = 0; i < tLen; i++) {
			while (j > 0 && t[i] != p[j]) {
				j = fail[j - 1];
			}
			if (t[i] == p[j]) {
				if (j == pLen - 1) {
					v.push_back(i - pLen + 2);
					j = fail[j];
				}
				else {
					j++;
				}
			}
		}
	}
	cout << v.size() << "\n";
	for (int k : v) cout << k << "\n";
}