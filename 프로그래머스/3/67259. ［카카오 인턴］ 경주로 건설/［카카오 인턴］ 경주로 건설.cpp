#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[25][25][4];
queue<pair<pair<int,int>,int>> q;
int n;
bool range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
int solution(vector<vector<int>> board) {
    memset(vis,-1,sizeof(vis));
    n=board.size();
    for(int i=0;i<4;i++){
        q.push({{0,0},i});
        vis[0][0][i]=0;
    }
    
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dir=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nd=i;
            
            int nCost=(dir==i?100:600)+vis[x][y][dir];
            if(range(nx,ny)&&!board[nx][ny]&&(vis[nx][ny][nd]==-1||vis[nx][ny][nd]>nCost)){
                vis[nx][ny][nd]=nCost;
                q.push({{nx,ny},nd});
            }
        }
    }
    int answer=-1;
    for(int i=0;i<4;i++){
        if(vis[n-1][n-1][i]==-1){
            continue;
        }
        if(answer==-1||answer>vis[n-1][n-1][i]){
            answer=vis[n-1][n-1][i];
        }
    }
    return answer;
}