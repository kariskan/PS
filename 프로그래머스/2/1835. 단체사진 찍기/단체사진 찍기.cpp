#include <string>
#include <vector>

using namespace std;

char seq[8]={'A','C','F','J','M','N','R','T'};
int n,answer;
vector<string> d;

bool valid(vector<char> now){
    for(int i=0;i<d.size();i++){
        for(int j=0;j<now.size();j++){
            for(int k=j+1;k<now.size();k++){
                if((now[j]==d[i][0]&&now[k]==d[i][2])||(now[j]==d[i][2]&&now[k]==d[i][0])){
                    if(d[i][3]=='='){
                        if(k-j-1!=d[i][4]-'0'){
                            return false;
                        }
                    }else if(d[i][3]=='>'){
                        if(k-j-1<=d[i][4]-'0'){
                            return false;
                        }
                    }else if(d[i][3]=='<'){
                        if(k-j-1>=d[i][4]-'0'){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
void go(vector<char> now,vector<int> vis){
    if(now.size()==8){
        if(valid(now)){
            answer++;
        }
        return;
    }
    for(int i=0;i<8;i++){
        if(!vis[i]){
            vis[i]=1;
            now.push_back(seq[i]);
            go(now,vis);
            vis[i]=0;
            now.pop_back();
        }
    }
}

int solution(int n, vector<string> data) {
    ::n=n;
    d=data;
    answer = 0;
    vector<int> vis(8);
    go({}, vis);
    return answer;
}