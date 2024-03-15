#include <string>
#include <vector>
#include <queue>
using namespace std;

int vis[25][25][4];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n;
bool range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
int solution(vector<vector<int>> board) {
    n=board.size();
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<4;i++){
        q.push({{0,0},i});
        vis[0][0][i]=1;
    }
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dir=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int cost=vis[x][y][dir]+(dir==i?100:600);
            if(range(nx,ny)&&board[nx][ny]==0&&(!vis[nx][ny][i]||vis[nx][ny][i]>cost)){
                vis[nx][ny][i]=cost;
                q.push({{nx,ny},i});
            }
        }
    }
    int answer=-1;
    for(int i=0;i<4;i++){
        if(vis[n-1][n-1][i]==0){
            continue;
        }
        if(answer==-1||answer>vis[n-1][n-1][i]){
            answer=vis[n-1][n-1][i]-1;
        }
    }
    return answer;
}