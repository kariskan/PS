#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int p[100];
int Find(int x){
    if(p[x]==x){
        return x;
    }
    return p[x]=Find(p[x]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    p[b]=a;
}
bool compare(vector<int>&v1,vector<int>&v2){
    return v1[2]<v2[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),compare);
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    for(int i=0;i<costs.size();i++){
        if(Find(costs[i][0])!=Find(costs[i][1])){
            Union(costs[i][0],costs[i][1]);
            answer+=costs[i][2];
        }
    }
    return answer;
}