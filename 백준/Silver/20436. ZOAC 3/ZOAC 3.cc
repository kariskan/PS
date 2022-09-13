#include <iostream>
using namespace std;

char a;
string s;

int x[26] = { 1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2 };
int y[26] = { 0,4,2,2,2,3,4,5,7,6,7,8,6,5,8,9,0,3,1,4,6,3,1,1,5,0 };

int main() {
	cin >> a;
	int leftx = x[a - 'a'];
	int lefty = y[a - 'a'];
	
	cin >> a;
	int rightx = x[a - 'a'];
	int righty = y[a - 'a'];

	cin >> s;

	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'y' || s[i] == 'u' || s[i] == 'i' || s[i] == 'o' || s[i] == 'p' ||
			s[i] == 'h' || s[i] == 'j' || s[i] == 'k' || s[i] == 'l' || s[i] == 'b' || s[i] == 'n' || s[i] == 'm') {
			ans += abs(rightx - x[s[i] - 'a']) + abs(righty - y[s[i] - 'a']);
			rightx = x[s[i] - 'a'];
			righty = y[s[i] - 'a'];
		}
		else {
			ans += abs(leftx - x[s[i] - 'a']) + abs(lefty - y[s[i] - 'a']);
			leftx = x[s[i] - 'a'];
			lefty = y[s[i] - 'a'];
		}
	}

	cout << ans + s.length();
}