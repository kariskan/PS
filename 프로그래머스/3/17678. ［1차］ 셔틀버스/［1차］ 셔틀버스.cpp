#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vis(24*60+1);
string toStringTime(int t){
    string res="";
    if(t/60<10){
        res+="0"+to_string(t/60);
    }else {
        res+=to_string(t/60);
    }
    res+=":";
    if(t%60<10){
        res+="0"+to_string(t%60);
    }else{
        res+=to_string(t%60);
    }
    return res;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer="";
    for(string t:timetable){
        vis[stoi(t.substr(0,2))*60+stoi(t.substr(3))]++;
    }
    for(int i=0;i<=23*60+59;i++){
        vector<int> temp=vis;
        temp[i]++;
        int lastIdx=0;
        for(int j=9*60;j<=9*60+(n-1)*t;j+=t){
            int cnt=m;
            while(cnt&&lastIdx<=j){
                int mi=min(cnt,temp[lastIdx]);
                cnt-=mi;
                temp[lastIdx]-=mi;
                if(temp[lastIdx]==0){
                    lastIdx++;
                }
            }
        }
        if(temp[i]==0){
            answer=toStringTime(i);
        }
    }
    return answer;
}