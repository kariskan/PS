#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n < m)cout << "<";
	else if (n > m)cout << ">";
	else cout << "==";
}