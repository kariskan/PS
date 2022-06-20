#include <iostream>
using namespace std;
int a[301][301], b[602][602];

int main() {
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	for (int i = 1; i <= h + x; i++) {
		for (int j = 1; j <= w + y; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= h; i++) {
 		for (int j = 1; j <= w; j++) {
			if (i >= x + 1 && j >= y + 1) {
				a[i][j] = b[i][j] - a[i - x][j - y];		
			}
			else {
				a[i][j] = b[i][j];
			}
			cout <<a[i][j]<<  " ";
		}
		cout << "\n";
	}

}