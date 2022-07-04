#include <iostream>
using namespace std;
int kingX, kingY, dolX, dolY;
int x[8] = { 0,0,1,-1,-1,-1,1,1 };
int y[8] = { 1,-1,0,0,1,-1,1,-1 };
int main() {
	string s;
	cin >> s;
	kingX = 8 - (s[1] - '0');
	kingY = s[0] - 'A';
	cin >> s;
	dolX = 8 - (s[1] - '0');
	dolY = s[0] - 'A';
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int ktX = kingX, ktY = kingY;
		int dX = dolX, dY = dolY;
		int dir;
		if (s == "R") {
			dir = 0;
		}
		else if (s == "L") {
			dir = 1;
		}
		else if (s == "B") {
			dir = 2;
		}
		else if (s == "T") {
			dir = 3;
		}
		else if (s == "RT") {
			dir = 4;
		}
		else if (s == "LT") {
			dir = 5;
		}
		else if (s == "RB") {
			dir = 6;
		}
		else {
			dir = 7;
		}
		ktX += x[dir];
		ktY += y[dir];
		if (ktX >= 0 && ktX < 8 && ktY >= 0 && ktY < 8) {
			if (ktX == dolX && ktY == dolY) {
				dX += x[dir];
				dY += y[dir];
				if (dX >= 0 && dX < 8 && dY >= 0 && dY < 8) {
					kingX = ktX;
					kingY = ktY;
					dolX = dX;
					dolY = dY;
				}
			}
			else {
				kingX = ktX;
				kingY = ktY;
			}
		}
	}
	cout << (char)(kingY + 'A') << 8 - kingX << '\n' << (char)(dolY + 'A') << 8 - dolX;
}