// #include <string>
// #include <vector>

// using namespace std;

// int sum[3600000*24+2];
// int toTime(string s){
//     s=s.substr(11);
//     int hour=stoi(s.substr(0,2));
//     int minute=stoi(s.substr(3,2));
//     int second=stoi(s.substr(6,2));
//     int milli=stoi(s.substr(9,3));
//     return hour*3600000+minute*60000+second*1000+milli;
// }
// int getDuration(string s){
//     return stod(s.substr(24, s.length()-25))*1000;
// }
// int solution(vector<string> lines) {
//     int answer = 0;
//     for(string line:lines){
//         int end=toTime(line);
//         int duration=getDuration(line);
//         int start=max(0,end-duration+1);
//         printf("%d %d %d\n", start, duration, end);
//         sum[start]++;
//         sum[end+1]--;
//     }
//     for(int i=1;i<=3600000*24;i++){
//         sum[i]+=sum[i-1];
//     }
//     for(int i=1;i<=3600000*24;i++){
//         sum[i]+=sum[i-1];
//     }
    
//     answer=sum[0];
//     printf("%d\n", sum[3605001]);
//     for(int i=0;i<=3600000*24;i++){
//         if(i<=1000){
//             answer=max(answer,sum[i]);
//         }else{
//             answer=max(answer,sum[i]-sum[i-1001]);
//         }
//     }
//     return answer;
// }

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int toTime(string s){
    s=s.substr(11);
    int hour=stoi(s.substr(0,2));
    int minute=stoi(s.substr(3,2));
    int second=stoi(s.substr(6,2));
    int milli=stoi(s.substr(9,3));
    return hour*3600000+minute*60000+second*1000+milli;
}
int getDuration(string s){
    return stod(s.substr(24, s.length()-25))*1000;
}
int solution(vector<string> lines) {
    int answer = 0;
    priority_queue<int> q;
    vector<pair<int,int>> v;
    for(string line:lines){
        int end=toTime(line);
        int duration=getDuration(line);
        int start=max(0,end-duration+1);
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        q.push(-v[i].second);
        while(!q.empty()&&-q.top()+999<v[i].first){
            q.pop();
        }
        answer=max(answer,(int)q.size());
    }
    
    return answer;
}