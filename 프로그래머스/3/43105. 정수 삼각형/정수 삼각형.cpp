#include <string>
#include <vector>

using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size();
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }   
            if(i==n-1){
                answer=max(answer,dp[i][j]);
            }
        }
    }
    return answer;
}