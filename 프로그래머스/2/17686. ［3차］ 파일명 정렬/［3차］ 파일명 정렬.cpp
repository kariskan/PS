#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string toLower(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}
bool compare(pair<vector<string>,int>&v1,pair<vector<string>,int>&v2){
    if(toLower(v1.first[0])==toLower(v2.first[0])){
        if(stoi(v1.first[1])==stoi(v2.first[1])){
            return v1.second<v2.second;
        }
        return stoi(v1.first[1])<stoi(v2.first[1]);
    }
    return toLower(v1.first[0])<toLower(v2.first[0]);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<vector<string>,int>> v;
    for(int i=0;i<files.size();i++){
        vector<string> t;
        int idx1=0;
        while(idx1<files[i].length()&&!(files[i][idx1]>='0'&&files[i][idx1]<='9')){
            idx1++;
        }
        int idx2=idx1;
        while(idx2<files[i].length()&&files[i][idx2]>='0'&&files[i][idx2]<='9'){
            idx2++;
        }
        t.push_back(files[i].substr(0,idx1));
        t.push_back(files[i].substr(idx1,idx2-idx1));
        if(idx2<files[i].length()){
            t.push_back(files[i].substr(idx2));
        }
        v.push_back({t,i});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        string temp="";
        for(int j=0;j<v[i].first.size();j++){
            temp+=v[i].first[j];
        }
        answer.push_back(temp);
    }
    return answer;
}