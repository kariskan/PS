#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,x,y;
vector<vector<pair<int, int>>> v;
vector<int> dis;

void dijk(int source) {
    
    priority_queue<pair<int, int>> pq;
    pq.push({0,source});
    dis[source] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        for(auto&i:v[node]) {
            int nxNode = i.first;
            int nxCost = cost + i.second;
            
            if(dis[nxNode] > nxCost) {
                dis[nxNode] = nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>x>>y;
    v.resize(n);
    dis.resize(n, 987654321);
    
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    dijk(y);
    sort(dis.begin(), dis.end());
    
    int ans = 0, cnt = 0;
    
    for(int i=0;i<n;i++){
        if(dis[i] * 2 > x) {
            cout<<-1;
            return 0;
        }
        if((dis[i] + cnt) * 2 > x) {
            ans++;
            cnt = dis[i];
        }
        else cnt += dis[i];
    }
    
    if(cnt) ans++;
    
    cout<<ans;
}
