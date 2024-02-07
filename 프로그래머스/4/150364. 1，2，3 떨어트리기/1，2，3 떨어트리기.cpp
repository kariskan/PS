#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[101];
vector<vector<int>> v;
vector<int> t,target,answer,seq;
bool stop=false;
void findMinimumAnswer(){
    if(!answer.empty()&&answer[0]==-1){
        return;
    }
    for(int i=0;i<seq.size();i++){
        int mi=max(1,target[seq[i]-1]-(t[seq[i]-1]-1)*3);
        answer.push_back(mi);
        target[seq[i]-1]-=mi;
        t[seq[i]-1]--;
    }
}
int check(){
    for(int i=0;i<t.size();i++){
        if(t[i]>target[i]){
            return -1;
        }
        if(!(t[i]<=target[i]&&t[i]*3>=target[i])){
            return 0;
        }
    }
    return 1;
}
void go(int now){
    if(v[now].empty()){
        seq.push_back(now);
        t[now-1]++;
        int c = check();
        if(c==1||c==-1){
            stop=true;
            if(c==-1){
                answer={-1};
            }
        }
        return;
    }
    go(v[now][cnt[now]]);
    cnt[now]=(cnt[now]+1)%v[now].size();
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    v.resize(target.size()+1);
    t.resize(target.size());
    ::target=target;
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i=0;i<v.size();i++){
        sort(v[i].begin(),v[i].end());
    }
    while(!stop){
        go(1);
    }
    findMinimumAnswer();
    return answer;
}