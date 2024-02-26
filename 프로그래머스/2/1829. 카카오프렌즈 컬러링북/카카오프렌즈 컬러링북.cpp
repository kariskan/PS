#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<int> solution(int n, int m, vector<vector<int>> picture) {
    int vis[100][100]={0,};    
    vector<int> answer={0,0};
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&picture[i][j]){
                vis[i][j]=1;
                q.push({i,j});
                int cnt=0;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    cnt++;
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&picture[nx][ny]==picture[i][j]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                answer[1]=max(answer[1],cnt);
                answer[0]++;
            }
        }
    }
    return answer;
}