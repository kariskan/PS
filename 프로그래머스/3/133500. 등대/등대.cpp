#include <string>
#include <vector>

using namespace std;
int dp[100001][2];
vector<vector<int>> v;
int go(int node,int pre,int flag){
    if(dp[node][flag]){
        return dp[node][flag];
    }
    int res=0;
    for(auto&i:v[node]){
        if(i!=pre){
            if(flag==0){
                res+=go(i,node,1);
            }else{
                res+=min(go(i,node,1),go(i,node,0));
            }
        }
    }
    return dp[node][flag]=res+flag;
}

int solution(int n, vector<vector<int>> lighthouse) {
    v.resize(n+1);
    for(vector<int> light:lighthouse){
        v[light[0]].push_back(light[1]);
        v[light[1]].push_back(light[0]);
    }
    return min(go(1,0,1),go(1,0,0));
}