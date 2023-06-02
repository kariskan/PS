#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a,b,c;
int vis[300000];
int main() {
    string s;cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'){
            a.push_back(i);
        }else if(s[i]=='B'){
            b.push_back(i);
        }else {
            c.push_back(i);
        }
    }
    int ans = 0, aidx = 0, bidx = 0, cidx = 0;
    
    while (bidx < b.size() && cidx < c.size()) {
        if (b[bidx] < c[cidx] && !vis[bidx]) {
            vis[bidx] = 1;
            bidx++;
            ans++;
        }
        cidx++;
    }
    bidx = 0;
    while (aidx < a.size() && bidx < b.size()) {
        if (a[aidx] < b[bidx] && !vis[bidx]) {
            vis[bidx] = 1;
            bidx++;
            aidx++;
            ans++;
        } else {
            bidx++;
        }
    }
    
    cout << ans;
}