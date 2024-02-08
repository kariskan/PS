#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
vector<int> info;
int answer;
void go(int now, int sheep, int wolf, queue<int> q) {
    sheep += 1 - info[now];
    wolf += info[now];
    if(sheep<=wolf){
        return;
    }
    answer=max(answer,sheep);

    for(auto&i:v[now]){
        q.push(i);
    }

    int siz=q.size();
    for(int i=0;i<siz;i++){
        int node=q.front();
        q.pop();
        go(node,sheep,wolf,q);
        q.push(node);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    ::info=info;
    v.resize(info.size());
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    go(0,0,0,{});
    return answer;
}