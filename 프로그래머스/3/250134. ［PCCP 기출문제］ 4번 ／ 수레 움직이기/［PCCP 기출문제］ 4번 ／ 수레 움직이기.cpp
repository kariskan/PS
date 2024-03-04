#include <string>
#include <vector>

using namespace std;
int n,m,answer;
int redVis[4][4], blueVis[4][4];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<vector<int>> maze;
int range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}

void go(int redx,int redy,int bluex,int bluey,bool redArrive, bool blueArrive,int cnt){
    if(redArrive&&blueArrive){
        if(answer==0||answer>cnt){
            answer=cnt;
        }
        return;
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int nrx=redx,nry=redy,nbx=bluex,nby=bluey;
            if(!redArrive){
                nrx+=dx[i];
                nry+=dy[i];
            }
            if(!blueArrive){
                nbx+=dx[j];
                nby+=dy[j];
            }
            
            if(range(nrx,nry)&&range(nbx,nby)&&(redArrive||!redVis[nrx][nry])&&(blueArrive||!blueVis[nbx][nby])&&maze[nrx][nry]!=5&&maze[nbx][nby]!=5){
                if(nrx==bluex&&nry==bluey&&nbx==redx&&nby==redy){
                    continue;
                }
                if(nrx==nbx&&nry==nby){
                    continue;
                }
                redVis[nrx][nry]=1;
                blueVis[nbx][nby]=1;
                go(nrx,nry,nbx,nby,maze[nrx][nry]==3?1:0,maze[nbx][nby]==4?1:0,cnt+1);
                redVis[nrx][nry]=0;
                blueVis[nbx][nby]=0;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    ::maze=maze;
    n=maze.size(),m=maze[0].size();
    int redx,redy,bluex,bluey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]==1){
                redx=i;
                redy=j;
                redVis[i][j]=1;
            }
            if(maze[i][j]==2){
                bluex=i;
                bluey=j;
                blueVis[i][j]=1;
            }
        }
    }
    go(redx,redy,bluex,bluey,false,false,0);
    return answer;
}