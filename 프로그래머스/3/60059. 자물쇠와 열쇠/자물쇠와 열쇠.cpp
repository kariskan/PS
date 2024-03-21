#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v){
    vector<vector<int>> res=v;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            res[i][j]=v[j][(int)v.size()-i-1];
        }
    }
    return res;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n=key.size(),m=lock.size();
    
    for(int i=0;i<n+m;i++){
        for(int j=0;j<n+m;j++){
            for(int k=0;k<4;k++){
                key=rotate(key);
                vector<vector<int>> temp=lock;
                for(int i1=0;i1<n;i1++){
                    for(int j1=0;j1<n;j1++){
                        int x=i+i1-n+1;
                        int y=j+j1-n+1;
                        if(x>=0&&x<m&&y>=0&&y<m){
                            temp[x][y]^=key[i1][j1];
                        }
                    }
                }
                bool flag=true;
                for(int i1=0;i1<m;i1++){
                    for(int j1=0;j1<m;j1++){
                        if(temp[i1][j1]==0){
                            flag=false;
                        }
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
    }
    return false;
}