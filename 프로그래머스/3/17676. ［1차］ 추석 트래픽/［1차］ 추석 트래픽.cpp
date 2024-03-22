#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
pair<int,int> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    string start=v[1];
    string duration=v[2];
    duration.pop_back();
    int end=stoi(start.substr(0,2))*3600000+stoi(start.substr(3,2))*60000
            +stoi(start.substr(6,2))*1000+stoi(start.substr(9));
    int st=end-stod(duration.substr(0))*1000+1;
    return {st,end};
}
int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<int,int>> v;
    for(string line:lines){
        v.push_back(parse(line));
    }
    sort(v.begin(),v.end());
    priority_queue<int> q;
    for(int i=0;i<v.size();i++){
        q.push(-v[i].second);
        while(!q.empty()&&-q.top()+1000<=v[i].first){
            q.pop();
        }
        answer=max(answer,(int)q.size());
    }
    return answer;
}