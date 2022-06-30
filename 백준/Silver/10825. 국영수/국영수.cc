#include <iostream>
#include <algorithm>
using namespace std;

typedef struct student {
	string name;
	int ko;
	int en;
	int ma;
};

bool compare(student& a, student& b) {
	if (a.ko == b.ko) {
		if (a.en == b.en) {
			if (a.ma == b.ma) {
				return a.name < b.name;
			}
			return a.ma > b.ma;
		}
		return a.en < b.en;
	}
	return a.ko > b.ko;
}

student a[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].ko >> a[i].en >> a[i].ma;
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		cout << a[i].name << '\n';
	}
}