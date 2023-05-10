#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<char> v;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());

    vector<string> v2;

    do {
        string t = "";
        for (int i = 0; i < v.size(); i++) {
            t += v[i];
        }
        v2.push_back(t);
    } while (next_permutation(v.begin(), v.end()));
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] > s) {
            cout << v2[i];
            return 0;
        }
    }
    cout << 0;
}