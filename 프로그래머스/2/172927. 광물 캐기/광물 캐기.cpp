#include <string>
#include <vector>

using namespace std;
int answer = 1000000000;
vector<string> minerals;
int getP(int source, string target){
    if(source==0){
        return 1;
    }
    if(source==1){
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

void go(vector<int> picks, int idx, int p){
    if(idx>=minerals.size()||(picks[0]==0&&picks[1]==0&&picks[2]==0)){
        answer=min(answer,p);
        return;
    }
    if(picks[0]>0){
        picks[0]-=1;
        int preP = p;
        for(int i=idx;i<min((int)minerals.size(),idx+5);i++){
            preP+=getP(0,minerals[i]);
        }
        go(picks,idx+5,preP);
        picks[0]+=1;
    }
    if(picks[1]>0){
        picks[1]-=1;
        int preP = p;
        for(int i=idx;i<min((int)minerals.size(),idx+5);i++){
            preP+=getP(1,minerals[i]);
        }
        go(picks,idx+5,preP);
        picks[1]+=1;
    }
    if(picks[2]>0){
        picks[2]-=1;
        int preP = p;
        for(int i=idx;i<min((int)minerals.size(),idx+5);i++){
            preP+=getP(2,minerals[i]);
        }
        go(picks,idx+5,preP);
        picks[2]+=1;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    ::minerals=minerals;
    go(picks,0,0);
    return answer;
}