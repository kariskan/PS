#include <string>
#include <vector>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<ll,ll>> v;
    ll maxx=LLONG_MIN,maxy=LLONG_MIN,minx=LLONG_MAX,miny=LLONG_MAX;
    for(int i=0;i<line.size();i++){
        for(int j=i+1;j<line.size();j++){
            ll bfed=(ll)line[i][1]*line[j][2]-(ll)line[i][2]*line[j][1];
            ll adbc=(ll)line[i][0]*line[j][1]-(ll)line[i][1]*line[j][0];
            ll ecaf=(ll)line[i][2]*line[j][0]-(ll)line[i][0]*line[j][2];
            if(adbc==0){
                continue;
            }
            if(bfed%adbc==0&&ecaf%adbc==0){
                ll x=bfed/adbc;
                ll y=ecaf/adbc;
                v.insert({x,y});
                maxx=max(maxx,x);
                maxy=max(maxy,y);
                minx=min(minx,x);
                miny=min(miny,y);
            }
        }
    }
    answer.resize(maxy-miny+1);
    for(int i=0;i<answer.size();i++){
        string s(maxx-minx+1,'.');
        answer[i]=s;
    }
    for(auto&i:v){
        ll x=i.first;
        ll y=i.second;
        answer[maxy-y][x-minx]='*';
    }
    return answer;
}