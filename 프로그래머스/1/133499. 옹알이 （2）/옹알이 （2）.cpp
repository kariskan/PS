#include <string>
#include <vector>

using namespace std;

vector<string> babbling;
string s[4]={"aya","ye","woo","ma"};
int answer,maxLen,vis[100];
void go(string now, int pre) {
    if(now.length()>maxLen){
        return;
    }
    for(int i=0;i<babbling.size();i++){
        if(now==babbling[i]&&!vis[i]){
            vis[i]=1;
            answer++;
        }
    }
    
    for(int i=0;i<4;i++){
        if(i==pre){
            continue;
        }
        go(now+s[i],i);
    }
}

int solution(vector<string> babbling) {
    ::babbling=babbling;
    for(int i=0;i<babbling.size();i++){
        maxLen=max((int)babbling[i].length(),maxLen);
    }
    go("",-1);
    return answer;
}