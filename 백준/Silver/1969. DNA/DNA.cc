#include <iostream>
using namespace std;
string a[1000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ar[50][26] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ar[j][a[i][j] - 'A']++;
		}
	}
	string ans;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int tempMax = -1;
		char tempC;
		for (int j = 0; j < 26; j++) {
			if (ar[i][j] && (tempMax == -1 || tempMax < ar[i][j])) {
				tempMax = ar[i][j];
				tempC = j + 'A';
			}
		}
		ans += tempC;
		sum += n - tempMax;
	}
	cout << ans << '\n' << sum;
}