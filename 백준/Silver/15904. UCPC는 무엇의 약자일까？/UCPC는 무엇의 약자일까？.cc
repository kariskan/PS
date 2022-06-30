#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (cnt == 0 && s[i] == 'U') {
			cnt++;
		}
		else if (cnt == 1 && s[i] == 'C') {
			cnt++;
		}
		else if (cnt == 2 && s[i] == 'P') {
			cnt++;
		}
		else if (cnt == 3 && s[i] == 'C') {
			cnt++;
		}
	}
	if (cnt == 4)cout << "I love UCPC";
	else cout << "I hate UCPC";
}