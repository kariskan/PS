#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string& s1, string& s2) { return s1 + s2 < s2 + s1; }

int main() {
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end(), compare);
    if (s[s.size() - 1][0] == '0') {
        cout << 0;
        return 0;
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
}