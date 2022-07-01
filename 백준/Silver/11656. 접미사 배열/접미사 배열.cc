#include <iostream>
#include <set>
using namespace std;
set<string> s;
int main() {
	string se;
	cin >> se;
	for (int i = 0; i < se.length(); i++) {
		string t = "";
		for (int j = i; j < se.length(); j++) {
			t += se[j];
		}
		s.insert(t);
	}
	for (auto i : s) {
		cout << i << '\n';
	}
}