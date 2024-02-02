#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
map<string,int> playMap;
map<string,priority_queue<pair<int, int>>> genreMap;
bool compare(pair<string,int>&p1,pair<string,int>&p2){
    return p1.second>p2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        playMap[genres[i]]+=plays[i];
        genreMap[genres[i]].push({plays[i],-i});
    }
    vector<pair<string,int>> genreV;
    for(auto&i:playMap){
        genreV.push_back({i.first,i.second});
    }
    sort(genreV.begin(),genreV.end(),compare);
    for(int i=0;i<genreV.size();i++){
        string genre=genreV[i].first;
        int siz=min(2,(int)genreMap[genre].size());
        for(int j=0;j<siz;j++){
            answer.push_back(-genreMap[genre].top().second);
            genreMap[genre].pop();
        }
    }
    return answer;
}