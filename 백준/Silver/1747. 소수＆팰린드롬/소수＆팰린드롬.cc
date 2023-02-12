#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int a[20000001] = { 0, };
bool isPalindrome(int n) {
	string a = to_string(n);
	for (int i = 0; i < a.length() / 2; i++) {
		if (a[i] != a[a.length() - i - 1])return false;
	}
	return true;
}
void isPrimNumber() { //0이면 소수
	for (int i = 2; i <= sqrt(20000000); i++) {
		if (a[i] == 1)continue;
		for (int j = i * 2; j <= 20000000; j += i) {
			if (a[j] == 1)continue;
			a[j] = 1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	a[1] = 1;
	isPrimNumber();
	for (int i = n;; i++) {
		if (isPalindrome(i) && a[i] == 0) {
			cout << i; break;
		}
	}
}