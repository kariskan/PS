#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;
string s;
set<string> se;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        se.insert(s);
    }
	
	int ans = 0;

    for (auto& i : se) {
        if (i.length() >= 6 && i.substr(i.length() - 6) == "Cheese") {
            ans++;
        }
    }

    cout << (ans >= 4 ? "yummy" : "sad");
}