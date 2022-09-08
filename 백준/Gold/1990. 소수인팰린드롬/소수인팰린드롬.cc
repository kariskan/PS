#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPrime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}

	return true;
}

bool palindrome[10000001];

void isPalindrome(int a, int b) {
	for (int i = a; i <= b; i++) {
		string s1 = to_string(i);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		if (s1 == s2) palindrome[i] = 1;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	isPalindrome(a, min(10000000, b));
	for (int i = a; i <= min(10000000, b); i++) {
		if (palindrome[i])
			if (isPrime(i)) {
				cout << i << '\n';
			}
	}
	cout << -1;
}