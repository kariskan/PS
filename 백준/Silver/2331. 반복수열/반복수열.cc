#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<long long> s;
vector<long long> v;
int a, p;
long long get(long long n) {
	long long res = 0;
	while (n) {
		int t = 1;
		for (int i = 0; i < p; i++) {
			t *= (n % 10);
		}
		res += t;
		n /= 10;
	}
	return res;
}
int main() {
	cin >> a >> p;
	s.insert(a);
	v.push_back(a);
	long long num = a;
	while (1) {
		num = get(num);
		if (s.find(num) != s.end()) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == num) {
					cout << i;
					return 0;
				}
			}
		}
		s.insert(num);
		v.push_back(num);
	}
}