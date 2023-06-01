#include <iostream>
using namespace std;

int vis[26][14], cnt[26];

pair<int, int> parse(string s) {
    int a = s[0] - 'A';
    int b = (s[1] - '0') * 10 + (s[2] - '0');
    return {a, b};
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i += 3) {
        string t = s.substr(i, i + 3);
        pair<int, int> par = parse(t);
        if (vis[par.first][par.second]) {
            cout << "GRESKA\n";
            return 0;
        }
        vis[par.first][par.second] = 1;
        cnt[par.first]++;
    }
    cout << 13 - cnt['P' - 'A'] << ' ' << 13 - cnt['K' - 'A'] << ' '
         << 13 - cnt['H' - 'A'] << ' ' << 13 - cnt['T' - 'A'];
}