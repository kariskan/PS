#include <string>
#include <vector>

using namespace std;

int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int n,answer=-1;
vector<vector<int>> clockHands;
int rot[8];
void go(int idx){
    if(idx==n){
        vector<vector<int>> v=clockHands;
        int total=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<5;k++){
                int nx=dx[k];
                int ny=i+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<n){
                    v[nx][ny]=(v[nx][ny]+rot[i])%4;
                }
            }
            total+=rot[i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i-1][j]==0){
                    continue;
                }
                int c=4-v[i-1][j];
                for(int k=0;k<5;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n){
                        v[nx][ny]=(v[nx][ny]+c)%4;
                    }
                }
                total+=c;
            }
        }
        bool flag=true;
        for(int j=0;j<n;j++){
            if(v[n-1][j]){
                flag=false;
                break;
            }
        }
        if(flag){
            if(answer==-1||answer>total){
                answer=total;
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        rot[idx]=i;
        go(idx+1);
    }
}

int solution(vector<vector<int>> clockHands) {
    ::clockHands=clockHands;
    n=clockHands.size();
    go(0);
    return answer;
}