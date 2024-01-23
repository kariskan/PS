#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long, long long>> coor;
    long long minx=LLONG_MAX,miny=LLONG_MAX,maxx=LLONG_MIN,maxy=LLONG_MIN;
    for(int i=0;i<line.size();i++){
        for(int j=i+1;j<line.size();j++){
            long long BF_ED = (long long)line[i][1]*line[j][2]-(long long)line[i][2]*line[j][1];
            long long EC_AF = (long long)line[i][2]*line[j][0]-(long long)line[i][0]*line[j][2];
            long long AD_BC = (long long)line[i][0]*line[j][1]-(long long)line[i][1]*line[j][0];
            if(!AD_BC||BF_ED%AD_BC!=0||EC_AF%AD_BC!=0){
                continue;
            }
            long long x=BF_ED/AD_BC;
            long long y=EC_AF/AD_BC;
            minx=min(minx,x);
            maxx=max(maxx,x);
            miny=min(miny,y);
            maxy=max(maxy,y);
            coor.insert({x,y});
        }
    }
    for(long long i=0;i<maxy-miny+1;i++){
        string s(maxx-minx+1,'.');
        answer.push_back(s);
    }
    for(auto& i:coor){
        answer[maxy-i.second][i.first-minx]='*';
    }
    return answer;
}