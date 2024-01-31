#include <string>
#include <vector>
#include <climits>
using namespace std;
int n, dp[201][201];
vector<vector<int>> matrix;
int go(int start, int end){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]){
        return dp[start][end];
    }
    int res=INT_MAX;
    for(int i=start;i<end;i++){
        int l=go(start,i);
        int r=go(i+1,end);
        res=min(res,l+r+matrix[start][0]*matrix[i][1]*matrix[end][1]);
    }
    return dp[start][end]=res;
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    matrix=matrix_sizes;
    n=matrix_sizes.size();
    
    return go(0,n-1);
}