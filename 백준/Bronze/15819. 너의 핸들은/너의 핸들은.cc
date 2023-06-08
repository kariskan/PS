#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
string s[100];

bool compare(string &s1, string &s2) {
    for (int i = 0; i < min((int)s1.length(), (int)s2.length()); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] < s2[i];
        }
    }
    return s1.length() < s2.length();
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, compare);
    cout << s[m - 1];
}