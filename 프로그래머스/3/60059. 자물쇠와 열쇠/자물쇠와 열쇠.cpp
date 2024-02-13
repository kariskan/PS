#include <string>
#include <vector>

using namespace std;
int map[40][40];
vector<vector<int>> rotate(vector<vector<int>> key){
    vector<vector<int>> res(key.size(),vector<int>(key.size()));
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key.size();j++){
            res[i][j]=key[j][key.size()-i-1];
        }
    }
    return res;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n=key.size(),m=lock.size();
    for(int i=n-1;i<n-1+m;i++){
        for(int j=n-1;j<n-1+m;j++){
            map[i][j]=lock[i-n+1][j-n+1];
        }
    }
    for(int i=0;i<=n+m-2;i++){
        for(int j=0;j<=n+m-2;j++){
            for(int r=0;r<4;r++){
                key=rotate(key);
                bool flag=true;
                for(int i1=n-1;i1<=n+m-2;i1++){
                    for(int j1=n-1;j1<=n+m-2;j1++){
                        if(i1>=max(i,n-1)&&i1<=min(n+m-2,i+n-1)&&j1>=max(j,n-1)&&j1<=min(n+m-2,j+n-1)){
                            if((map[i1][j1]^key[i1-i][j1-j])==0){
                                flag=false;
                                break;
                            }
                        }else{
                            if(map[i1][j1]==0){
                                flag=false;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        break;
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