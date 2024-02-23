#include <string>
#include <algorithm>
#include <map>
using namespace std;
bool isChar(char a){
    return (a>='A'&&a<='Z')||(a>='a'&&a<='z');
}
string toLower(string s){
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
int solution(string str1, string str2) {
    int answer = 0;
    str1=toLower(str1);
    str2=toLower(str2);
    vector<string> v1,v2;
    for(int i=0;i<str1.length()-1;i++){
        string temp=str1.substr(i,2);
        if(!isChar(temp[0])||!isChar(temp[1])){
            continue;
        }
        v1.push_back(temp);
    }
    for(int i=0;i<str2.length()-1;i++){
        string temp=str2.substr(i,2);
        if(!isChar(temp[0])||!isChar(temp[1])){
            continue;
        }
        v2.push_back(temp);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    map<string,int> ma1,ma2,N,U;
    for(int i=0;i<v1.size();i++){
        ma1[v1[i]]++;
    }
    for(int i=0;i<v2.size();i++){
        ma2[v2[i]]++;
    }
    for(auto&i:ma1){
        if(N.find(i.first)==N.end()){
            if(ma2.find(i.first)!=ma2.end()){
                N[i.first]=min(i.second,ma2[i.first]);
            }
        }
        if(U.find(i.first)==U.end()){
            if(ma2.find(i.first)==ma2.end()){
                U[i.first]=i.second;
            }else{
                U[i.first]=max(i.second,ma2[i.first]);                
            }
        }
    }
    for(auto&i:ma2){
        if(N.find(i.first)==N.end()){
            if(ma1.find(i.first)!=ma1.end()){
                N[i.first]=min(i.second,ma1[i.first]);
            }
        }
        if(U.find(i.first)==U.end()){
            if(ma1.find(i.first)==ma1.end()){
                U[i.first]=i.second;
            }else{
                U[i.first]=max(i.second,ma1[i.first]);
            }
        }
    }
    
    if(U.size()==0){
        return 65536;
    }
    int nsum=0,usum=0;
    for(auto&i:N){
        nsum+=i.second;
    }
    for(auto&i:U){
        usum+=i.second;
    }
    return ((double)nsum/usum)*65536;
}