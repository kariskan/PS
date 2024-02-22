#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string,string> name;
vector<string> parse(string s){
    stringstream ss(s);
    vector<string> res;
    string temp;
    while(getline(ss,temp,' ')){
        res.push_back(temp);
    }
    return res;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        vector<string> v=parse(record[i]);
        if(v[0]=="Enter"||v[0]=="Change"){
            name[v[1]]=v[2];
        }
    }
    for(int i=0;i<record.size();i++){
        vector<string> v=parse(record[i]);
        if(v[0]=="Enter"){
            answer.push_back(name[v[1]]+"님이 들어왔습니다.");
        }else if(v[0]=="Leave"){
            answer.push_back(name[v[1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}