#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main() {
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		s.insert(a % 42);
	}
	cout << s.size();
}