#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string tolower(string s){
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            res+=s[i]-'A'+'a';
        }else{
            res+=s[i];
        }
    }
    return res;
}

vector<string> parse(string file){
    vector<string> v;
    string s="";
    int idx=0;
    for(int i=0;i<file.length();i++){
        if(file[i]>='0'&&file[i]<='9'){
            idx=i;
            v.push_back(s);
            break;
        }
        s+=file[i];
    }
    s="";
    for(int i=idx;i<file.length();i++){
        if(file[i]<'0'||file[i]>'9'){
            break;
        }
        s+=file[i];
    }
    v.push_back(s);
    idx+=s.length();
    if(idx<file.length()){
        v.push_back(file.substr(idx));
    }
    return v;
}

bool compare(pair<string,int>& s1, pair<string,int>& s2){
    vector<string> v1=parse(s1.first);
    vector<string> v2=parse(s2.first);
    if(tolower(v1[0])==tolower(v2[0])){
        if(stoi(v1[1])==stoi(v2[1])){
            return s1.second<s2.second;
        }
        return stoi(v1[1])<stoi(v2[1]);
    }
    return tolower(v1[0])<tolower(v2[0]);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string,int>> v;
    for(int i=0;i<files.size();i++){
        v.push_back({files[i],i});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    return answer;
}