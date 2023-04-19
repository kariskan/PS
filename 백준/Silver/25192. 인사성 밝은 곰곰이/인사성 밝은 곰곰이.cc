#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    set<string> se;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "ENTER") {
            ans += se.size();
            se.size();
            se.clear();
        } else {
            se.insert(s);
        }
    }
    ans += se.size();
    cout << ans;
}