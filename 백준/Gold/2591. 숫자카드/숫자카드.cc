#include <iostream>
#include <string>
using namespace std;

int dp[41];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (i < 2 && stoi(s.substr(0, i + 1)) <= 34 && stoi(s.substr(0, i + 1)) > 0 && s.substr(0, i + 1)[0] != '0') {
            dp[i]++;
        }
        for (int j = 0; j < i; j++) {
            string t = s.substr(j + 1, i - j);
            if (t.length() <= 2 && stoi(t) <= 34 &&stoi(t) > 0 && t[0] != '0') {
                dp[i] += dp[j];
            }
        }
    }    
    cout << dp[s.length() - 1];
}