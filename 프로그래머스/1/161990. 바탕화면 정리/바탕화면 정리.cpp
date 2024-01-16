#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minx=50,miny=50,maxx=0,maxy=0;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].length();j++){
            if(wallpaper[i][j]=='#'){
                minx=min(i,minx);
                miny=min(j,miny);
                maxx=max(i+1,maxx);
                maxy=max(j+1,maxy);
            }
        }
    }
    return {minx,miny,maxx,maxy};
}