#include <iostream>
#include <set>
using namespace std;
string s;
set<string> se;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		string t = "";
		t += s[i];
		se.insert(t);
		for (int j = i + 1; j < s.length(); j++) {
			t += s[j];
			se.insert(t);
		}
	}
	cout << se.size();
}