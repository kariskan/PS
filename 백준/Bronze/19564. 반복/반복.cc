#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] > s[i - 1]) {
            continue;
        }
        ans++;
    }
    cout << ans;
}