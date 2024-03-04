#include <string>
#include <vector>

using namespace std;
int dp[100001][2];
vector<vector<int>> v;
int go(int now,int pre,bool flag){
    if(dp[now][flag]){
        return dp[now][flag];
    }
    int res=(flag?1:0);
    for(auto&i:v[now]){
        if(i!=pre){
            if(flag){
                res+=min(go(i,now,0),go(i,now,1));
            }else{
                res+=go(i,now,1);
            }
        }
    }
    return dp[now][flag]=res;
}
int solution(int n, vector<vector<int>> lighthouse) {
    v.resize(n+1);
    for(vector<int> l:lighthouse){
        v[l[0]].push_back(l[1]);
        v[l[1]].push_back(l[0]);
    }
    return min(go(1,0,0),go(1,0,1));
}