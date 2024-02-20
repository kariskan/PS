#include <string>
#include <vector>

using namespace std;
vector<int> info,answer;
int n;
int getScore(vector<int> now){
    int rion=0,peach=0;
    for(int i=0;i<11;i++){
        if(now[i]==0&&info[i]==0){
            continue;
        }
        if(now[i]>info[i]){
            rion+=(10-i);
        }else{
            peach+=(10-i);
        }
    }
    if(now[10]==10){
        printf("%d %d\n", rion,peach);
    }
    return rion-peach;
}
bool lower(vector<int> now){
    for(int i=10;i>=0;i--){
        if(now[i]==0&&answer[i]==0){
            continue;
        }
        if(now[i]>answer[i]){
            return true;
        }else if(now[i]<answer[i]){
            return false;
        }
    }
    return false;
}
void go(vector<int> now,int idx,int rest){
    if(idx>=info.size()){
        now[10]+=rest;
        int score=getScore(now);
        if(score<=0){
            return;
        }
        if(answer.empty()||score>answer[11]||(score==answer[11]&&lower(now))){
            answer=now;
            answer.push_back(score);
        }
        return;
    }
    go(now,idx+1,rest);
    int mi=min(info[idx]+1,rest);
    now[idx]+=mi;
    go(now,idx+1,rest-mi);
    now[idx]-=mi;
}

vector<int> solution(int n, vector<int> info) {
    ::n=n;
    ::info=info;
    vector<int> now(11);
    go(now,0,n);
    if(answer.empty()){
        return {-1};
    }
    answer.pop_back();
    return answer;
}