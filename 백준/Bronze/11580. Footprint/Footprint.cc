#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<pair<int, int>> se;
    int x = 0, y = 0;
    se.insert({0, 0});
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') {
            y++;
        } else if (s[i] == 'W') {
            y--;
        } else if (s[i] == 'S') {
            x++;
        } else {
            x--;
        }
        se.insert({x, y});
    }
    cout << se.size();
}