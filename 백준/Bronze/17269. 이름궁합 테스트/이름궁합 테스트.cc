#include <iostream>
#include <string>
using namespace std;

int toNum[27] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;
    int idx = 0;
    string t = "";
    while (idx < s1.length() || idx < s2.length()) {
        if (idx < s1.length()) {
            t += toNum[s1[idx] - 'A']+'0';
        }
        if (idx < s2.length()) {
            t += toNum[s2[idx] - 'A']+'0';
        }
        idx++;
    }
    while (t.length() > 2) {
        string nt = "";
        for (int i = 1; i < t.length(); i++) {
            nt += (((t[i] - '0') + (t[i - 1] - '0')) % 10+'0');
        }
        t = nt;
    }
    cout << stoi(t) << '%';
}