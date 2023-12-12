#include <iostream>
using namespace std;

int main() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 4) == "XXXX") {
			for (int j = i; j < i + 4; j++)s[j] = 'A';
			i += 3;
		}
		else if (s.substr(i, 2) == "XX") {
			for (int j = i; j < i + 2; j++)s[j] = 'B';
			i++;
		}
		if (s[i] == 'X') {
			cout << -1;
			return 0;
		}
	}
	cout << s;
}