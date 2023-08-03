#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        if (s2.find(s1[i]) == string::npos) {
            cout << -1;
            return 0;
        }
    }
    string s = "";
    for (int i = 0; i < s2.length(); i++) {
        if (s1.find(s2[i]) != string::npos) {
            s += s2[i];
        }
    }
    
    int ans = s1.length();
    int left = 0, right = s1.length();
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        string t = "";
        for (int i = 0; i < mid; i++) {
            t += s;
        }
        
        int idx1 = 0, idx2 = 0;
        while (idx1 < t.length() && idx2 < s1.length()) {
            if (t[idx1] == s1[idx2]) {
                idx1++;
                idx2++;
                continue;
            }
            idx1++;
        }
        
        if (idx2 == s1.length()) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans;
}