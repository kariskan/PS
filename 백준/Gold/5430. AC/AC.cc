#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
#include <sstream>
using namespace std;

vector<string> parse(string s) {
    s = s.substr(1, s.length() - 2);
    stringstream ss(s);
    string temp;
    vector<string> v;
    while (getline(ss, temp, ',')) {
        v.push_back(temp);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        deque<int> d;
        string s;
        cin >> s;
        int n;
        cin >> n;
        string s2;
        cin >> s2;
        vector<string> p = parse(s2);
        for (auto &i: p) {
            d.push_back(stoi(i));
        }

        bool front = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                front = !front;
            } else {
                if (d.empty()) {
                    cout << "error\n";
                    break;
                }
                if (front) {
                    d.pop_front();
                } else {
                    d.pop_back();
                }
            }
            if (i == s.length() - 1) {
                cout << "[";
                for (int j = 0; j < d.size(); j++) {
                    cout << d[front ? j : d.size() - j - 1];
                    if (j < d.size() - 1) {
                        cout << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }
}
