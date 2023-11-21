#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	string v = "";
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == ':') {
			if (v.length() != 0)v += ':';
			if (i + 1 < len && s[i + 1] == ':') {
				int cnt = 0;
				for (int j = 0; j < i; j++) {
					if (s[j] == ':')cnt++;
				}
				for (int j = i + 2; j < len; j++) {
					if (s[j] == ':')cnt++;
				}
				if (i != 0)cnt++;
				for (int j = 0; j < 7 - cnt; j++) {
					for (int k = 0; k < 4; k++) {
						v += '0';
					}
					v += ':';
				}
				v.pop_back();
			}
			else {
				i++;
				string temp = "";
				while (i < s.length() && s[i] != ':') {
					temp += s[i];
					i++;
				}
				for (int j = 0; j < 4 - temp.length(); j++) {
					v += '0';
				}
				v += temp;
				i--;
			}
		}
		else {
			string temp = "";
			while (i < s.length() && s[i] != ':') {
				temp += s[i];
				i++;
			}
			for (int j = 0; j < 4 - temp.length(); j++) {
				v += '0';
			}
			v += temp;
			i--;
		}
	}
	cout << v;
}