#include <iostream>
#include <string>
using namespace std;
int dp[2500][2500];
string s;
int go(int left,int right){
    if(left>right){
        return 0;
    }
    if(left==right){
        return dp[left][right]=1;
    }
    if(dp[left][right]){
        return dp[left][right];
    }
    int l=go(left,right-1);
    int r=go(left+1,right);
    int mid=go(left+1,right-1);
    
    if(mid==right-left-1&&s[left]==s[right]){
        mid+=2;
    }
    return dp[left][right]=max(l,max(r,mid));
}
int solution(string s) {
    ::s=s;
    return go(0,s.length()-1);
}