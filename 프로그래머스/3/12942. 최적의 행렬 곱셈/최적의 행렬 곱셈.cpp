#include <string>
#include <vector>

using namespace std;
vector<vector<int>> matrix;
int dp[200][200];
int go(int left, int right){
    if(left>=right){
        return 0;
    }
    if(dp[left][right]){
        return dp[left][right];
    }
    int res=2*1e9;
    for(int i=left;i<right;i++){
        res=min(res,matrix[left][0]*matrix[i][1]*matrix[right][1]+go(left,i)+go(i+1,right));
    }
    return dp[left][right]=res;
}
int solution(vector<vector<int>> matrix) {
    ::matrix=matrix;
    return go(0,matrix.size()-1);
}