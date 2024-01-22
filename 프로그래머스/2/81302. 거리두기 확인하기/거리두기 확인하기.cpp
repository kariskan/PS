#include <string>
#include <vector>

using namespace std;

int dx[12]={-2,-1,-1,-1,0,0,0,0,1,1,1,2};
int dy[12]={0,-1,0,1,-2,-1,1,2,-1,0,1,0};
vector<string> place;

int getDis(int x, int y, int nx, int ny){
    return abs(x-y)+abs(nx-ny);
}

bool valid(int x, int y, int nx, int ny){
    int dis = getDis(x,y,nx,ny);
    if(dis==1){
        return false;
    }
    if(x==nx){
        if(place[x][(y+ny)/2]=='X'){
            return true;
        }
        return false;
    }
    if(y==ny){
        if(place[(x+nx)/2][y]=='X'){
            return true;
        }
        return false;
    }
    return place[nx][y]=='X'&&place[x][ny]=='X';
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string> place:places){
        ::place=place;
        bool flag=true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j]=='P'){
                    for(int k=0;k<12;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0&&nx<5&&ny>=0&&ny<5&&place[nx][ny]=='P'&&!valid(i,j,nx,ny)){
                            flag=false;
                            printf("%d %d %d %d\n", i,j,nx,ny);
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        answer.push_back(flag);
    }
    return answer;
}