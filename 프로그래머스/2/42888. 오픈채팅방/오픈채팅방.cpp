#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map<string,string> uid;
vector<string> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        vector<string> p=parse(record[i]);
        if(p[0]=="Change"||p[0]=="Enter"){
            uid[p[1]]=p[2];
        }
    }
    for(int i=0;i<record.size();i++){
        vector<string> p=parse(record[i]);
        if(p[0]=="Enter"){
            answer.push_back(uid[p[1]]+"님이 들어왔습니다.");
        }else if(p[0]=="Leave"){
            answer.push_back(uid[p[1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}