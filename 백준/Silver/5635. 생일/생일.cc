#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct student {
	string name;
	int day;
	int month;
	int year;
};

bool compare(const student& s1, const student& s2) {
	if (s1.year == s2.year) {
		if (s1.month == s2.month) {
			return s1.day < s2.day;
		}
		return s1.month < s2.month;
	}
	return s1.year < s2.year;
}

int main() {
	int n;
	cin >> n;
	vector<student> v;
	for (int i = 0; i < n; i++) {
		struct student std;
		cin >> std.name >> std.day >> std.month >> std.year;
		v.push_back(std);
	}
	sort(v.begin(), v.end(), compare);
	cout << v[v.size() - 1].name << '\n' << v[0].name;
}