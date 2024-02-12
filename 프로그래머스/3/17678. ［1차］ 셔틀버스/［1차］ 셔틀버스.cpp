#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int toTime(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
string toTime(int t){
    string res="";
    if(t/60<10){
        res+="0"+to_string(t/60);
    }else{
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
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<timetable.size();i++){
        q.push(toTime(timetable[i]));
    }
    
    for(int time=9*60+(n-1)*t;time>=0;time--){
        priority_queue<int,vector<int>,greater<int>> temp=q;
        temp.push(time);
        for(int i=9*60,cnt=0;cnt<n;cnt++,i+=t){
            int mCnt=m;
            while(!temp.empty()&&temp.top()<=i&&mCnt){
                mCnt--;
                temp.pop();
            }
        }
        if(temp.empty()||temp.top()>time){
            printf("%d\n", time);
            answer=toTime(time);
            break;
        }
    }
    return answer;
}