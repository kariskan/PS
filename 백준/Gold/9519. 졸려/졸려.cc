#include <iostream>
#include <algorithm>
using namespace std;

string nextCycle(string s) {
    int left = 0, right = s.length() - 1;
    string res = "";
    while (left < right) {
        res += s[left++];
        res += s[right--];
    }
    if (left == right) {
        res += s[left];
    }
    return res;
}

int getPeriod(string s) {
    int res = 0;
    string t = s;
    while (1) {
        t = nextCycle(t);
        res++;
        if (t == s) {
            return res;
        }
    }
}

int main() {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int len = s.length();
    x %= getPeriod(s);
    while (x--) {
        string left = "", right = "";
        int idx = 0;
        while (idx < s.length()) {
            left += s[idx++];
            if (idx < s.length()) {
                right += s[idx++];
            }
        }
        reverse(right.begin(), right.end());
        s = left + right;
    }
    cout << s;
}