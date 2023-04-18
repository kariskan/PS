#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;

    for (int i = 0; i < s.length(); i++) {
        int dif = 0;
        for (int j = 0; j <= i; j++) {
            if (s[j] != s[s.length() - 1 - i + j]) {
                dif++;
            }
        }
        if (dif == 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}