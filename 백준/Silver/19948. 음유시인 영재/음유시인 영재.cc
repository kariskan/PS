#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int getIdx(char a) {
    if (a >= 'a' && a <= 'z') {
        return a - 'a';
    }
    return a - 'A';
}

char toUpper(int idx) {
    return char(idx + 'A');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);
    int n;
    cin >> n;
    int a[26];
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }
    string ans = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (temp.back() == s[i]) {
            continue;
        }
        temp += s[i];
        if (s[i] == ' ') {
            n--;
        }
    }

    s = temp;
    stringstream ss(s);
    vector<string> v;
    while (getline(ss, temp, ' ')) {
        if (!temp.empty()) {
            v.push_back(temp);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        string t = v[i];
        for (int j = 0; j < t.length(); j++) {
            int idx = getIdx(t[j]);
            a[idx]--;
            if (j == 0) {
                a[idx]--;
                ans += toUpper(idx);
            }
        }
    }
//
//    cout << n << '\n';
//    for (int i = 0; i < 26; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << '\n';
    if (n < 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] < 0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}