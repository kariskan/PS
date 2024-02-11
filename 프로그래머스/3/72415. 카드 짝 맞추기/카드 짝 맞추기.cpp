#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
pair<pair<int,int>,pair<int,int>> pos[7];
vector<vector<int>> s;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool range(int x,int y){
    return x>=0&&x<4&&y>=0&&y<4;
}
bool edge(int x,int y){
    return x==0||x==3||y==0||y==3;
}
int getDis(vector<vector<int>> board,int sx,int sy,int ex,int ey){
    int vis[4][4]={0};
    queue<pair<int,int>> q;

    q.push({sx,sy});
    vis[sx][sy]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==ex&&y==ey){
            return vis[x][y]-1;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(range(nx,ny)&&!vis[nx][ny]){
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
            while(range(nx,ny)&&board[nx][ny]==0){
                nx+=dx[i];
                ny+=dy[i];
            }
            if(!range(nx,ny)){
                nx-=dx[i];
                ny-=dy[i];
            }
            if(range(nx,ny)&&(board[nx][ny]||edge(nx,ny))&&vis[nx][ny]==0){
                q.push({nx,ny});
                vis[nx][ny]=vis[x][y]+1;
            }
        }
    }
}
void go(int idx, vector<int> v){
    if(idx==0){
        s.push_back(v);
        return;
    }
    v.push_back(0);
    go(idx-1,v);
    v.back()=1;
    go(idx-1,v);
}
int solution(vector<vector<int>> board, int r, int c) {
    int answer = INT_MAX;
    vector<int> seq;

    int maxBoard=0;
    for(int i=1;i<=6;i++){
        pos[i].first={-1,-1};
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]>0){
                if(pos[board[i][j]].first.first==-1){
                    pos[board[i][j]].first={i,j};
                }else{
                    pos[board[i][j]].second={i,j};
                }
                seq.push_back(board[i][j]);
                maxBoard=max(maxBoard,board[i][j]);
            }
        }
    }
    sort(seq.begin(),seq.end());
    seq.erase(unique(seq.begin(),seq.end()),seq.end());

    go(maxBoard,{});
    do{
        for(int i=0;i<s.size();i++){
            int nowX=r,nowY=c;
            vector<vector<int>> temp=board;
            int tempAnswer=0;
            for(int j=0;j<seq.size();j++){
                int x1,y1,x2,y2;
                if(s[i][j]==0){
                    x1=pos[seq[j]].first.first;
                    y1=pos[seq[j]].first.second;
                    x2=pos[seq[j]].second.first;
                    y2=pos[seq[j]].second.second;
                }else{
                    x1=pos[seq[j]].second.first;
                    y1=pos[seq[j]].second.second;
                    x2=pos[seq[j]].first.first;
                    y2=pos[seq[j]].first.second;
                }

                tempAnswer+=getDis(temp,nowX,nowY,x1,y1);
                temp[x1][y1]=0;
                nowX=x1,nowY=y1;
                tempAnswer+=getDis(temp,nowX,nowY,x2,y2);
                temp[x2][y2]=0;
                nowX=x2,nowY=y2;
            }
            answer=min(answer,tempAnswer);
        }
    }while(next_permutation(seq.begin(),seq.end()));
    return answer+maxBoard*2;
}

int main(){
    solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}},1,0);
}