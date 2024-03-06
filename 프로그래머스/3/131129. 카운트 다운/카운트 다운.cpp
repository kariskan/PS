#include <string>
#include <vector>

using namespace std;

pair<int,int> dp[100001];
vector<int> solution(int target) {
    vector<int> answer;
    
    for(int i=1;i<=target;i++){
        dp[i].first=dp[i].second=1e9;
    }
    for(int i=0;i<target;i++){
        for(int j=1;j<=20;j++){
            for(int k=1;k<=3;k++){
                int nx=i+j*k;
                if(nx>target){
                    continue;
                }
                pair<int,int> nd={dp[i].first+1,dp[i].second};
                if(k==1){
                    nd.second++;
                }
                if(dp[nx].first>nd.first||(dp[nx].first==nd.first&&dp[nx].second<nd.second)){
                    dp[nx]=nd;
                }
            }
        }
        if(i+50<=target){
            if(dp[i+50].first>dp[i].first+1||(dp[i+50].first==dp[i].first+1&&dp[i+50].second<dp[i].second+1)){
                dp[i+50]={dp[i].first+1,dp[i].second+1};
            }
        }
    }
    
    return {dp[target].first,dp[target].second};
}