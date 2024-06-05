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

int p[100001];

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    vector<pair<pair<int, int>, int>> v;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.second < b.second; });

    int ans = 0, cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first.first;
        int y = v[i].first.second;
        int cost = v[i].second;
        if (cnt == n - 2) {
            break;
        }
        if (Find(x) != Find(y)) {
            Union(x, y);
            ans += cost;
            cnt++;
        }
    }
    cout << ans;
}