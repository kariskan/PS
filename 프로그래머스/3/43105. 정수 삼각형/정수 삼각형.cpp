#include <string>
#include <vector>

using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]+triangle[i][j]);
            if(j>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
            }
            if(i==triangle.size()-1){
                answer=max(answer,dp[i][j]);
            }
        }
    }
    return answer;
}