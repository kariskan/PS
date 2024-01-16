#include <string>
#include <vector>
#include <sstream>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dirToNum(char dir) {
    if(dir=='E') return 0;
    if(dir=='W') return 1;
    if(dir=='S') return 2;
    return 3;
}

int parse(string s) {
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    return stoi(v[1]);
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int sx, sy;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].length();j++){
            if(park[i][j]=='S'){
                sx=i;
                sy=j;
            }
        }
    }
    int n=park.size(),m=park[0].size();
    for(string route:routes){
        int dir = dirToNum(route[0]);
        int cnt = parse(route);
        printf("%d %d\n", n, m);
        
        int tx=sx;
        int ty=sy;
        bool flag = true;
        for(int i=0;i<cnt;i++){
            int nx=tx+dx[dir];
            int ny=ty+dy[dir];
            if(!(nx>=0&&nx<n&&ny>=0&&ny<m&&park[nx][ny]!='X')){
                flag=false;
                break;
            }
            tx=nx;
            ty=ny;
            printf("%d %d\n", tx, ty);
        }
        if(flag){
            sx=tx;
            sy=ty;
        }
    }
    
    return {sx,sy};
}