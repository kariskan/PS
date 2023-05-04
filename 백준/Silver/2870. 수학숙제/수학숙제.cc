#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(string& s1, string& s2) {
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                return s1[i] < s2[i];
            }
        }
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

string eraseZero(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            return s.substr(i);
        }
    }
    if (s[0] == '0') {
        return "0";
    }
    return s;
}

vector<string> parse(string s) {
    string a = "";
    vector<string> v;
    for (int i = 0; i < s.length(); i++) {
        if (a != "" && !(s[i] >= '0' && s[i] <= '9')) {
            v.push_back(eraseZero(a));
            a = "";
        } else if (s[i] >= '0' && s[i] <= '9') {
            if (a == "") {
                a += s[i];
            } else {
                a += s[i];
            }
        }
    }
    if (a != "") {
        v.push_back(eraseZero(a));
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<string> res;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> v = parse(s);
        for (auto& j : v) {
            res.push_back(j);
        }
    }
    sort(res.begin(), res.end(), compare);
    for (auto& i : res) {
        cout << i << '\n';
    }
}