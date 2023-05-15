#include <iostream>
using namespace std;

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < s2.length(); i++) {
        int maxLen = 0;
        for (int j = 0; j < s1.length(); j++) {
            if (s2[i] == s1[j]) {
                int idx = 0;
                while (s2[i + idx] == s1[j + idx] && i + idx < s2.length() && j + idx < s1.length()) {
                    idx++;
                }
                if (maxLen < idx) {
                    maxLen = idx;
                }
            }
        }
        i += maxLen - 1;
        ans++;
    }
    
    cout << ans;
}