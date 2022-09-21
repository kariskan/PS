#include <iostream>
using namespace std;

int map[26][26];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b; string s;
		cin >> a >> s >> b;
		map[a - 'a'][b - 'a'] = 1;
	}

	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (i == j) continue;
				if (map[i][k] && map[k][j]) {
					map[i][j] = 1;
				}
			}
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b; string s;
		cin >> a >> s >> b;
		if (map[a - 'a'][b - 'a']) {
			cout << "T\n";
		}
		else cout << "F\n";
	}
}