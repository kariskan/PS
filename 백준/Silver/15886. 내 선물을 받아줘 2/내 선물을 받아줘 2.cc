#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;

	s.erase(unique(s.begin(), s.end()), s.end());

	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'E') ans++;
	}

	cout << ans;
}