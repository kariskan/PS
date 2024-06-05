#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;
//
//int vis[26];
//
//vector<string> split(string s){
//    stringstream ss(s);
//    vector<string> v;
//    string temp;
//    while(getline(ss,temp,' ')){
//        v.push_back(temp);
//    }
//    return v;
//}
//int toIdx(char c){
//    if(c>='a'&&c<='z'){
//        return c-'a';
//    }
//    return c-'A';
//}
//void shortOutput(string s){
//    vector<string> v=split(s);
//    for(string t:v){
//        if(!vis[toIdx(t[0])]){
//            vis[toIdx(t[0])]=1;
//            break;
//        }
//    }
//
//}
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        string s;
//        getline(cin, s);
//
//    }
//}

string dp[51];
int a[10];

string stringMax(string s1, string s2) {
    if (s1.empty()) {
        return s2;
    }
    if (s2.empty()) {
        return s1;
    }
    if (s1.length() > s2.length()) {
        return s1;
    }
    if (s1.length() < s2.length()) {
        return s2;
    }
    return max(s1, s2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = stringMax(dp[a[i]], to_string(i));
    }
    cin >> m;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (j + a[i] > m || dp[j].empty() || (dp[j] == "0" && i == 0)) {
                continue;
            }
            for (int k = 0; k <= dp[j].length(); k++) {
                string newString = dp[j].substr(0, k) + to_string(i) + dp[j].substr(k);
                dp[j + a[i]] = stringMax(dp[j + a[i]], newString);
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        ans = stringMax(ans, dp[i]);
    }
    cout << ans;
}