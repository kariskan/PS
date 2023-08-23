#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> ma = {{"a", 0},  {"b", 1},   {"k", 2},  {"d", 3},  {"e", 4},
                       {"g", 5},  {"h", 6},   {"i", 7},  {"l", 8},  {"m", 9},
                       {"n", 10}, {"ng", 11}, {"o", 12}, {"p", 13}, {"r", 14},
                       {"s", 15}, {"t", 16},  {"u", 17}, {"w", 18}, {"y", 19}};
int n;
string s[50];

bool compare(string &s1, string &s2) {
    vector<string> v1, v2;
    for (int i = 0; i < s1.length(); i++) {
        string t1;
        if (i < s1.length() - 1 && s1.substr(i, 2) == "ng") {
            t1 = "ng";
        } else {
            t1 = s1.substr(i, 1);
        }
        v1.push_back(t1);
    }
    for (int i = 0; i < s2.length(); i++) {
        string t1;
        if (i < s2.length() - 1 && s2.substr(i, 2) == "ng") {
            t1 = "ng";
        } else {
            t1 = s2.substr(i, 1);
        }
        v2.push_back(t1);
    }
    int len = min(v1.size(), v2.size());
    for (int i = 0; i < len; i++) {
        if (v1[i] == v2[i]) {
            continue;
        }
        return ma[v1[i]] < ma[v2[i]];
    }
    return v1.size() < v2.size();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, compare);
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}