#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(vector<int>& v1, vector<int>& v2){
    return v1[1]<v2[1];
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    int xCnt=0,yCnt=0;
    int board[5001][5001]={0,};
    map<int,int> xMap,yMap;
    sort(data.begin(),data.end());
    for(int i=0;i<data.size();i++){
        if(xMap.find(data[i][0])==xMap.end()){
            xMap[data[i][0]]=xCnt++;
        }
    }
    sort(data.begin(),data.end(),compare);
    for(int i=0;i<data.size();i++){
        if(yMap.find(data[i][1])==yMap.end()){
            yMap[data[i][1]]=yCnt++;
        }
    }
    
    for(int i=0;i<data.size();i++){
        board[xMap[data[i][0]]][yMap[data[i][1]]]++;
    }
    for(int i=1;i<=xCnt;i++){
        for(int j=1;j<=yCnt;j++){
            board[i][j]+=board[i-1][j]+board[i][j-1]-board[i-1][j-1];
        }
    }
    for(int i=0;i<data.size();i++){
        int x1=xMap[data[i][0]];
        int y1=yMap[data[i][1]];
        for(int j=i+1;j<data.size();j++){
            int x2=xMap[data[j][0]];
            int y2=yMap[data[j][1]];
            
            int maxX=max(x1,x2);
            int maxY=max(y1,y2);
            int minX=min(x1,x2);
            int minY=min(y1,y2);
            int cnt=board[maxX-1][maxY-1]-board[minX][maxY-1]
                -board[maxX-1][minY]+board[minX][minY];
            if(x1==x2||y1==y2||cnt>0){
                continue;
            }
            answer++;
        }
    }
    return answer;
}