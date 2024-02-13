#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> node;
vector<vector<int>> answer(2);
bool compare(vector<int>&v1,vector<int>&v2){
    if(v1[1]==v2[1]){
        return v1[0]<v2[0];
    }
    return v1[1]>v2[1];
}
void go(int now, int lx, int rx){
    if(now>=node.size()){
        return;
    }
    int left=-1,right=-1;
    answer[0].push_back(node[now][2]);
    for(int i=now+1;i<node.size();i++){
        if(left==-1&&node[i][1]<node[now][1]&&lx<node[i][0]&&node[now][0]>node[i][0]){
            go(i, lx, node[now][0]);
            left=i;
        }
        if(right==-1&&node[i][1]<node[now][1]&&rx>node[i][0]&&node[now][0]<node[i][0]){
            go(i,node[now][0],rx);
            right=i;
        }
    }
    answer[1].push_back(node[now][2]);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    node=nodeinfo;
    for(int i=0;i<nodeinfo.size();i++){
        node[i].push_back(i+1);
    }
    sort(node.begin(),node.end(),compare);
    int rmax=0,lmin=1e9;
    for(int i=0;i<nodeinfo.size();i++){
        rmax=max(rmax,nodeinfo[i][0]);
        lmin=min(lmin,nodeinfo[i][0]);
    }
    go(0,lmin-1,rmax+1);
    return answer;
}