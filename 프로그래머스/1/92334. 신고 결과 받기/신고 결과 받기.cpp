#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
using namespace std;

map<string, set<string>> record;
map<string, int> in, alert;

pair<string, string> parse(string s){
    stringstream ss(s);
    vector<string>v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return {v[0],v[1]};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(string r:report){
        auto i=parse(r);
        if(record[i.second].find(i.first)==record[i.second].end()){
            record[i.second].insert(i.first);
            in[i.second]++;
        }
    }
    for(string id:id_list){
        if(in[id]>=k){
            for(auto&i:record[id]){
                alert[i]++;
            }
        }
    }
    for(string id:id_list){
        answer.push_back(alert[id]);
    }
    return answer;
}