#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		string s; cin >> s;

		if (!next_permutation(s.begin(), s.end())) {
			prev_permutation(s.begin(), s.end());
		}

		cout << s << '\n';
	}
}