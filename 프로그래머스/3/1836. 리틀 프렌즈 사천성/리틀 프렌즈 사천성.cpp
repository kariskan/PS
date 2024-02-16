#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

pair<int,int> Find(int sx,int sy,vector<string> board){
    int n=board.size(),m=board[0].size();
    int vis[101][101][4][2]={0,};
    queue<pair<pair<int,int>,pair<int,int>>> q;

    for(int i=0;i<4;i++){
        vis[sx][sy][i][0]=1;
        q.push({{sx,sy},{i,0}});
    }

    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int dir=q.front().second.first;
        int flag=q.front().second.second;
        q.pop();

        if(board[x][y]==board[sx][sy]&&(x!=sx||y!=sy)){
            return {x,y};
        }

        for(int i=0;i<4;i++){
            if(flag&&dir!=i){
                continue;
            }
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nd=i;
            int nf=flag;
            if(dir!=i){
                nf=1;
            }
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny][nd][nf]
               &&(board[nx][ny]=='.'||board[nx][ny]==board[sx][sy])){
                q.push({{nx,ny},{nd,nf}});
                vis[nx][ny][nd][nf]=1;
            }
        }
    }
    return {-1,-1};
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    n=board.size(),m=board[0].size();

    while(1){
        vector<char> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>='A'&&board[i][j]<='Z'){
                    pair<int,int> p=Find(i,j,board);
                    if(p.first==-1){
                        continue;
                    }
                    v.push_back(board[p.first][p.second]);
                }
            }
        }
        if(v.empty()){
            break;
        }
        sort(v.begin(),v.end());
        answer+=v[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[0]==board[i][j]){
                    board[i][j]='.';
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]>='A'&&board[i][j]<='Z'){
                return "IMPOSSIBLE";
            }
        }
    }
    return answer;
}