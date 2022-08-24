#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for (int i = 1; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			string t1 = s.substr(0, i);
			string t2 = s.substr(i, j - i);
			string t3 = s.substr(j);
			
			if(t1.length() > 1)	reverse(t1.begin(), t1.end());
			if(t2.length() > 1)	reverse(t2.begin(), t2.end());
			if(t3.length() > 1)	reverse(t3.begin(), t3.end());

			if (ans > t1 + t2 + t3) ans = t1 + t2 + t3;
		}
	}

	cout << ans;
}