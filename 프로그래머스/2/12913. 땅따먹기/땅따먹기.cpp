#include <iostream>
#include <vector>
using namespace std;

int dp[100000][4];
int solution(vector<vector<int>> land){
    for(int i=0;i<4;i++){
        dp[0][i]=land[0][i];
    }
    int answer=0;
    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(j==k){
                    continue;
                }
                dp[i][j]=max(dp[i][j],land[i][j]+dp[i-1][k]);
            }
            if(i==land.size()-1){
                answer=max(answer,dp[i][j]);
            }
        }
    }
    return answer;
}