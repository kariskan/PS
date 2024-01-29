#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> v;
int n;
int isGates[50001],isSummits[50001];
vector<int> dijk(){
    vector<int> dis(n+1,INT_MAX);
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        if(isGates[i]){
            pq.push({INT_MAX,i});
        }
    }
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        
        for(auto&i:v[node]){
            int nxCost=max(cost,i.second);
            int nxNode=i.first;
            if(isGates[nxNode]){
                continue;
            }
            if(dis[nxNode]>nxCost){
                dis[nxNode]=nxCost;
                if(isSummits[nxNode]){
                    continue;
                }
                pq.push({-nxCost,nxNode});
            }
        }
    }
    return dis;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer={50000,10000000};
    ::n=n;
    v.resize(n+1);
    for(vector<int> path:paths){
        v[path[0]].push_back({path[1],path[2]});
        v[path[1]].push_back({path[0],path[2]});
    }
    int gSize=gates.size(),sSize=summits.size();
    for(int i=0;i<gSize;i++){
        isGates[gates[i]]=1;
    }
    for(int i=0;i<sSize;i++){
        isSummits[summits[i]]=1;
    }
    vector<int> d=dijk();
    for(int j=0;j<sSize;j++){
        int ans=d[summits[j]];
        if(answer[1]>ans||(answer[1]==ans&&answer[0]>summits[j])){
            answer={summits[j],ans};
        }
    }
    return answer;
}