#include <iostream>
using namespace std;

string s[100];
int vis[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1;
        ans++;
        int temp[26] = {0};
        for (int j = 0; j < s[i].length(); j++) {
            temp[s[i][j] - 'a']++;
        }
        for (int j = i + 1; j < n; j++) {
            int temp2[26] = {0};
            for (int k = 0; k < s[j].length(); k++) {
                temp2[s[j][k] - 'a']++;
            }
            bool flag = true;
            for (int k = 0; k < 26; k++) {
                if (temp[k] != temp2[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                vis[j] = 1;
            }
        }
    }
    cout << ans;
}