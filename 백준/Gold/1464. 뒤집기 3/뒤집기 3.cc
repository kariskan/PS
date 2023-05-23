#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] < s[i + 1]) {
            reverse(s.begin(), s.begin() + i + 1);
            reverse(s.begin(), s.begin() + i + 2);
        }
    }
    reverse(s.begin(), s.end());
    cout << s;
}