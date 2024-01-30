#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<int> dis(n+1,INT_MAX);
    priority_queue<pair<int,int>> pq;
    vector<vector<int>> v(n+1);
    
    for(vector<int> road:roads){
        v[road[0]].push_back(road[1]);
        v[road[1]].push_back(road[0]);
    }
    
    pq.push({0,destination});
    dis[destination]=0;
    
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        
        for(auto&i:v[node]){
            int nxCost=cost+1;
            int nxNode=i;
            if(dis[nxNode]>nxCost){
                dis[nxNode]=nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
    for(int source:sources){
        if(dis[source]==INT_MAX){
            answer.push_back(-1);
        }else{
            answer.push_back(dis[source]);
        }
    }
    return answer;
}