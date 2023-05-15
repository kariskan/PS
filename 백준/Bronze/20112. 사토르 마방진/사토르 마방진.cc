#include <iostream>
using namespace std;
string s[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        string t = s[i];
        for (int j = 0; j < n; j++) {
            if (t[j] != s[j][i]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}