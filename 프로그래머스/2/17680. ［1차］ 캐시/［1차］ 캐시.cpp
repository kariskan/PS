#include <string>
#include <vector>

using namespace std;

string tolower(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}

bool compare(string s1, string s2){
    return tolower(s1)==tolower(s2);
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0){
        return cities.size()*5;
    }
    int answer = 0;
    vector<pair<string,int>> v;
    int t=1;
    for(int i=0;i<cities.size();i++,t++){
        int idx=-1,last=1000000000,lastIdx=-1;
        for(int j=0;j<v.size();j++){
            if(compare(v[j].first,cities[i])){
                idx=j;
                v[j].second=t;
            }
            if(last>v[j].second){
                last=v[j].second;
                lastIdx=j;
            }
        }
        if(idx==-1){
            answer+=5;
            if(v.size()<cacheSize){
                v.push_back({cities[i],t});
            }else{
                v[lastIdx]={cities[i],t};
            }
        }else{
            answer++;
        }
    }
    return answer;
}