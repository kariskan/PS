#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    int c = 1;
    while (cin >> s1 >> s2) {
        if (s1 == "END" && s2 == "END") {
            break;
        }
        int m[27] = {0};
        for (int i = 0; i < s1.length(); i++) {
            m[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            m[s2[i] - 'a']--;
        }
        bool flag = true;
        for (int i = 0; i < 27; i++) {
            if (m[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Case " << c << ": same\n";
        } else {
            cout << "Case " << c << ": different\n";
        }

        c++;
    }
}