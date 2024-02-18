#include <string>
#include <vector>
#include <climits>
using namespace std;
int answer=INT_MAX;
vector<string> minerals;
int get(int now,string target){
    if(now==0){
        return 1;
    }
    if(now==1){
        if(target=="diamond"){
            return 5;
        }
        return 1;
    }
    if(target=="diamond"){
        return 25;
    }
    if(target=="iron"){
        return 5;
    }
    return 1;
}
void go(int p,vector<int> picks,int idx){
    if(idx>=minerals.size()||(picks[0]==0&&picks[1]==0&&picks[2]==0)){
        answer=min(answer,p);
        return;
    }
    for(int i=0;i<picks.size();i++){
        if(picks[i]==0){
            continue;
        }
        int newP=p;
        picks[i]--;
        for(int j=idx;j<min((int)minerals.size(),idx+5);j++){
            newP+=get(i,minerals[j]);
        }
        go(newP,picks,idx+5);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    ::minerals=minerals;
    go(0,picks,0);
    return answer;
}