#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int l = 1; l <= 9; l++) {
                    string s = to_string(i) + to_string(j) + to_string(k) +
                               to_string(l);
                    vector<string> t;
                    t.push_back(s);
                    for (int m = 1; m < 4; m++) {
                        string temp = s.substr(m) + s.substr(0, m);
                        t.push_back(temp);
                    }
                    sort(t.begin(), t.end());
                    v.push_back(t[0]);
                }
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()));

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s = to_string(a) + to_string(b) + to_string(c) + to_string(d);
    string cl = s;
    for (int i = 1; i < 4; i++) {
        cl = min(cl, s.substr(i) + s.substr(0, i));
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == cl) {
            cout << i + 1;
            return 0;
        }
    }
}