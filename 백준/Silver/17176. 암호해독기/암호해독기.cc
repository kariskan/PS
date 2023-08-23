#include <iostream>
#include <map>
using namespace std;

int main() {
    string ans = "";
    int n;
    cin >> n;
    map<char, int> ma;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            ma[' ']++;
        } else if (a <= 26) {
            ma[a - 1 + 'A']++;
        } else {
            ma[a - 27 + 'a']++;
        }
    }
    getchar();
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        ma[s[i]]--;
        if (ma[s[i]] < 0) {
            cout << 'n';
            return 0;
        }
    }
    cout << 'y';
}