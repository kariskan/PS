#include <string>
#include <vector>

using namespace std;
string toLower(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}
int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0){
        return cities.size()*5;
    }
    vector<pair<string,int>> v;
    int answer = 0;
    for(int i=0;i<cities.size();i++){
        cities[i]=toLower(cities[i]);
        bool flag=false;
        int mi=100000,miIdx=-1;
        for(int j=0;j<v.size();j++){
            if(v[j].first==cities[i]){
                flag=true;
                v[j].second=i;
            }
            if(mi>v[j].second){
                mi=v[j].second;
                miIdx=j;
            }
        }
        if(flag){
            answer++;
        }else{
            answer+=5;
            if(v.size()<cacheSize){
                v.push_back({cities[i],i});
            }else{
                v[miIdx]={cities[i],i};
            }
        }
    }
    return answer;
}