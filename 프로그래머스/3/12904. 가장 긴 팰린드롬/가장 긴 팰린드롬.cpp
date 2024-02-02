#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[2501][2501];
string s;
bool ispal(int l, int r){
    string ss=s.substr(l,r-l+1);
    string t=ss;
    reverse(t.begin(),t.end());
    return ss==t;
}
int go(int l,int r){
    if(l>r){
        return 0;
    }
    if(l==r){
        return 1;
    }
    if(dp[l][r]){
        return dp[l][r];
    }
    
    int left=go(l,r-1);
    int right=go(l+1,r);
    int mid=go(l+1,r-1);
    if(mid==r-1-l&&r>l&&s[l]==s[r]){
        mid+=2;
    }
    // printf("%d %d %d %d %d\n", l, r, left, right, mid);
    return dp[l][r]=max(left,max(right,mid));
}
int solution(string s) {
    ::s=s;
    return go(0,s.length()-1);
}