#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
int idx = 0;

void go(int left, int right) {
    if (left > right) {
        idx--;
        return;
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s1[idx] == s2[i]) {
            idx++;
            go(left, i - 1);
            idx++;
            go(i + 1, right);
            cout << s2[i];
            return;
        }
    }
}

int main() {
    while (1) {
        cin >> s1;
        if (cin.eof()) {
            break;
        }
        cin >> s2;
        idx = 0;
        go(0, s1.length() - 1);
        cout << "\n";
    }
}