#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int,int>>> v(N+1);
    vector<int> dis(N+1,1e9);
    for(int i=0;i<road.size();i++){
        v[road[i][0]].push_back({road[i][1],road[i][2]});
        v[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    priority_queue<pair<int,int>> pq;
    dis[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        
        if(dis[node]<cost){
            continue;
        }

        for(auto&i:v[node]){
            int nxCost=i.second+cost;
            int nxNode=i.first;
            if(dis[nxNode]>nxCost){
                dis[nxNode]=nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(dis[i]<=K){
            answer++;
        }
    }
    return answer;
}