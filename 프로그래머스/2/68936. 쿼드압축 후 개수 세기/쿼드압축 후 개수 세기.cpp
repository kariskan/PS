#include <string>
#include <vector>

using namespace std;
vector<vector<int>> arr;
pair<int,int> go(int x1, int y1, int x2, int y2){
    if(x1==x2&&y1==y2){
        if(arr[x1][y1]==1){
            return {0,1};
        }
        return {1,0};
    }
    bool flag=true;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(arr[i][j]!=arr[x1][y1]){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        if(arr[x1][y1]==1){
            return {0,1};
        }
        return {1,0};
    }
    pair<int,int> g1=go(x1,y1,(x1+x2)/2,(y1+y2)/2);
    pair<int,int> g2=go(x1,(y1+y2+1)/2,(x1+x2)/2,y2);
    pair<int,int> g3=go((x1+x2+1)/2,y1,x2,(y1+y2)/2);
    pair<int,int> g4=go((x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
    return {g1.first+g2.first+g3.first+g4.first,g1.second+g2.second+g3.second+g4.second};
}

vector<int> solution(vector<vector<int>> arr) {
    ::arr=arr;
    pair<int,int> g=go(0,0,arr.size()-1,arr.size()-1);
    return {g.first,g.second};
}