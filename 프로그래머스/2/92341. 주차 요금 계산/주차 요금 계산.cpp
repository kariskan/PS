#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string, int> record;
map<string, int> fee;
pair<int, pair<string, int>> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return {stoi(v[0].substr(0,2))*60+stoi(v[0].substr(3)),{v[1],v[2]=="IN"?1:0}};
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0;i<records.size();i++){
        pair<int,pair<string,int>> p=parse(records[i]);
        if(p.second.second==1){
            record[p.second.first]=p.first;
        }else{
            int diff=p.first-record[p.second.first];
            fee[p.second.first]+=diff;
            record.erase(p.second.first);
        }
    }
    for(auto&i:record){
        int diff=23*60+59-i.second;
        fee[i.first]+=diff;
    }
    for(auto&i:fee){
        if(i.second<=fees[0]){
            i.second=fees[1];
        }else{
            i.second=fees[1]+((i.second-fees[0]+fees[2]-1)/fees[2])*fees[3];
        }
    }
    for(auto&i:fee){
        answer.push_back(i.second);
    }
    return answer;
}