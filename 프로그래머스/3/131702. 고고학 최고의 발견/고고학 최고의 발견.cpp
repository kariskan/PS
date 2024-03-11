#include <string>
#include <vector>

using namespace std;
int n,rot[8],answer=-1;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<vector<int>> clockHands;
bool range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}

void go(int idx){
    if(idx==n){
        vector<vector<int>> v=clockHands;
        int cnt=0;
        for(int i=0;i<n;i++){
            v[0][i]=(v[0][i]+rot[i])%4;
            cnt+=rot[i];
            for(int k=0;k<4;k++){
                int nx=dx[k];
                int ny=i+dy[k];
                if(range(nx,ny)){
                    v[nx][ny]=(v[nx][ny]+rot[i])%4;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int rotCnt=(4-v[i-1][j])%4;
                cnt+=rotCnt;
                v[i][j]=(v[i][j]+rotCnt)%4;
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(range(nx,ny)){
                        v[nx][ny]=(v[nx][ny]+rotCnt)%4;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            if(v[n-1][j]){
                return;
            }
        }
        if(answer==-1||answer>cnt){
            answer=cnt;
        }
        return;
    }
    for(int i=0;i<4;i++){
        rot[idx]=i;
        go(idx+1);
    }
}
int solution(vector<vector<int>> clockHands) {
    n=clockHands.size();
    ::clockHands=clockHands;
    go(0);
    return answer;
}