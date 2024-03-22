#include <string>
#include <vector>
#include <sstream>
using namespace std;
int toSecond(string s){
    return stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6));
}
pair<int,int> getTime(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,'-')){
        v.push_back(temp);
    }
    return {toSecond(v[0]),toSecond(v[1])};
}
string toTimeString(int second){
    string res="";
    if(second/3600<10){
        res+="0"+to_string(second/3600);
    }else{
        res+=to_string(second/3600);
    }
    res+=":";
    if((second%3600)/60<10){
        res+="0"+to_string((second%3600)/60);
    }else{
        res+=to_string((second%3600)/60);
    }
    res+=":";
    if(second%60<10){
        res+="0"+to_string(second%60);
    }else{
        res+=to_string(second%60);
    }
    return res;
}
long long timeSum[100*3600+1];
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(int i=0;i<logs.size();i++){
        pair<int,int> p=getTime(logs[i]);
        int start=p.first;
        int end=p.second;
        timeSum[start]++;
        timeSum[end]--;
    }
    int totalTime=toSecond(play_time);
    int adv=toSecond(adv_time);
    for(int i=1;i<=totalTime;i++){
        timeSum[i]+=timeSum[i-1];
    }
    for(int i=1;i<=totalTime;i++){
        timeSum[i]+=timeSum[i-1];
    }
    long long maxTime=timeSum[adv-1],idx=0;
    for(int i=1;i<=totalTime-adv;i++){
        if(maxTime<timeSum[i+adv-1]-timeSum[i-1]){
            maxTime=timeSum[i+adv-1]-timeSum[i-1];
            idx=i;
        }
    }
    return toTimeString(idx);
}