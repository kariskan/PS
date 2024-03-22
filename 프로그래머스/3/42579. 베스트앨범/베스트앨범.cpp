#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<string,int> genreCnt;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        genreCnt[genres[i]]+=plays[i];
    }
    priority_queue<pair<int,string>> pq;
    for(auto&i:genreCnt){
        pq.push({i.second,i.first});
    }
    while(!pq.empty()){
        string genre=pq.top().second;
        pq.pop();
        vector<pair<int,int>> v;
        for(int i=0;i<genres.size();i++){
            if(genres[i]==genre){
                v.push_back({-plays[i],i});
            }
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<v.size();i++){
            answer.push_back(v[i].second);
            cnt++;
            if(cnt==2){
                break;
            }
        }
    }
    return answer;
}