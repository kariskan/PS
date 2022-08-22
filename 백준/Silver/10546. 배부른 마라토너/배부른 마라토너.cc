#include <iostream>
#include <map>
using namespace std;

map<string, int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t; cin >> t;
		s[t]++;
	}

	for (int i = 0; i < n - 1; i++) {
		string t; cin >> t;
		s[t]--;
	}

	for (auto& i : s) {
		if (i.second != 0) cout << i.first;
	}
}
