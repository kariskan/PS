#include <string>
#include <vector>

using namespace std;
long long sum[100*3700];
int toTime(string s){
    return stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
}
string toS2(int t){
    if(t==0){
        return "00";
    }
    if(t<10){
        return "0"+to_string(t);
    }
    return to_string(t);
}
string toS(int time){
    return toS2(time/3600)+":"+toS2((time%3600)/60)+":"+toS2(time%60);
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";
    long long ma=0;
    for(int i=0;i<logs.size();i++){
        int start=toTime(logs[i].substr(0,8));
        int end=toTime(logs[i].substr(9));
        
        sum[start]++;
        sum[end]--;
    }
    for(int i=1;i<=toTime(play_time);i++){
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=toTime(play_time);i++){
        sum[i]+=sum[i-1];
    }
    int adv=toTime(adv_time);
    for(int i=0;i<=toTime(play_time)-adv;i++){
        if(ma<sum[i+adv-1]-sum[i-1]){
            ma=sum[i+adv-1]-sum[i-1];
            answer=toS(i);
        }
    }
    return answer;
}