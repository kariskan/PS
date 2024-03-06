#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<pair<int,int>>> v;
bool isGate[50001], isSummit[50001];
int n;

vector<int> dijk(){
    int des=0,res=2*1e9;
    
    vector<int> dis(v.size(), 2*1e9);
    priority_queue<pair<int,int>> pq;
    
    for(int i=1;i<=n;i++){
        if(isGate[i]){
            pq.push({0,i});
            dis[i]=0;
        }
    }
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        
        if(isSummit[node]){
            if(res>cost||(res==cost&&des>node)){
                des=node;
                res=cost;
            }
            continue;
        }
        
        for(auto&i:v[node]){
            int nxNode=i.first;
            int nxCost=max(i.second,cost);
            if(nxCost<dis[nxNode]){
                dis[nxNode]=nxCost;
                if(isGate[nxNode]){
                    continue;
                }
                pq.push({-nxCost,nxNode});
            }
        }
    }
    return {des,res};
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    ::n=n;
    
    sort(gates.begin(),gates.end());
    sort(summits.begin(),summits.end());
    for(int gate:gates){
        isGate[gate]=true;
    }
    for(int summit:summits){
        isSummit[summit]=true;
    }
    v.resize(n+1);
    for(int i=0;i<paths.size();i++){
        v[paths[i][0]].push_back({paths[i][1],paths[i][2]});
        v[paths[i][1]].push_back({paths[i][0],paths[i][2]});
    }
    
    return dijk();
}