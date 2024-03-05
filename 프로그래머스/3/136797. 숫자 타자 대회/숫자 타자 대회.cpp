#include <string>
#include <vector>

using namespace std;
pair<int,int> pos[10]={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
int dp[100000][10][10];
string numbers;
int getCost(int now,int target){
    if(now==target){
        return 1;
    }
    pair<int,int> p1=pos[now];
    pair<int,int> p2=pos[target];
    int mi=min(abs(p1.first-p2.first),abs(p1.second-p2.second));
    int ma=max(abs(p1.first-p2.first),abs(p1.second-p2.second));
    return mi*3+(ma-mi)*2;
}
int go(int idx,int left,int right){
    if(idx>=numbers.length()){
        return 0;
    }
    if(dp[idx][left][right]){
        return dp[idx][left][right];
    }
    if(numbers[idx]-'0'==left||numbers[idx]-'0'==right){
        return dp[idx][left][right]=1+go(idx+1,left,right);
    }
    //왼손을 움직임
    int l=getCost(left,numbers[idx]-'0')+go(idx+1,numbers[idx]-'0',right);
    //오른손을 움직임
    int r=getCost(right,numbers[idx]-'0')+go(idx+1,left,numbers[idx]-'0');
    return dp[idx][left][right]=min(l,r);
}
int solution(string numbers) {
    ::numbers=numbers;
    return go(0,4,6);
}