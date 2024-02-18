#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int toTime(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
int solution(vector<vector<string>> book) {
    sort(book.begin(),book.end());
    priority_queue<int> q;
    for(int i=0;i<book.size();i++){
        int start=toTime(book[i][0]);
        int end=toTime(book[i][1])+10;
        if(q.empty()||-q.top()>start){
            q.push(-end);
            continue;
        }
        q.pop();
        q.push(-end);
    }
    return q.size();
}