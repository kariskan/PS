#include <string>
#include <vector>
#include <queue>
using namespace std;

int in[1000001],out[1000001],vis[1000001];
vector<vector<int>> v(1000001);
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    int n=0;
    for(auto&i:edges){
        in[i[1]]++;
        out[i[0]]++;
        v[i[0]].push_back(i[1]);
        n=max(n,max(i[0],i[1]));
    }
    
    int start;
    for(int i=1;i<=n;i++){
        if(in[i]==0&&out[i]>=2){
            start=i;
            break;
        }
    }
    answer[0]=start;
    
    queue<int> q;
    for(auto&i:v[start]){
        vis[i]=1;
        q.push(i);
        int nodeCnt=0,edgeCnt=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            nodeCnt++;
            edgeCnt+=v[node].size();
            
            for(auto&j:v[node]){
                if(!vis[j]){
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
        
        if(edgeCnt==nodeCnt){ // 도넛
            answer[1]++;
        }else if(edgeCnt==nodeCnt-1){ // 막대
            answer[2]++;
        }else{ // 8자
            answer[3]++;
        }
    }
    return answer;
}