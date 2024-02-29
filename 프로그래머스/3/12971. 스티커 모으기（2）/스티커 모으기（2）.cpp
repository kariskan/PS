#include <iostream>
#include <vector>
using namespace std;

int dp[100001][2];
int solution(vector<int> sticker){
    dp[1][1]=sticker[0];
    for(int i=2;i<=sticker.size();i++){
        dp[i][0]=max(dp[i-1][0],dp[i-2][0]+sticker[i-1]);
        dp[i][1]=max(dp[i-1][1],dp[i-2][1]+sticker[i-1]);
        if(i==sticker.size()){
            dp[i][1]=dp[i-1][1];
        }
    }
    return max(dp[sticker.size()][0],dp[sticker.size()][1]);
}