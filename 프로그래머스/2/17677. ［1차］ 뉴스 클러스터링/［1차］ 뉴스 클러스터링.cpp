#include <string>
#include <map>
using namespace std;

string tolower(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}

bool alphabet(char a){
    return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int> v1,v2;
    for(int i=0;i<str1.length()-1;i++){
        if(!alphabet(str1[i])||!alphabet(str1[i+1])){
            continue;
        }
        v1[tolower(str1.substr(i,2))]++;
    }
    for(int i=0;i<str2.length()-1;i++){
        if(!alphabet(str2[i])||!alphabet(str2[i+1])){
            continue;
        }
        v2[tolower(str2.substr(i,2))]++;
    }
    
    int n=0,u=0;
    for(auto&i:v1){
        for(auto&j:v2){
            if(i.first==j.first){
                n+=min(i.second,j.second);
            }
        }
    }
    for(auto&i:v1){
        printf("%s ", i.first.c_str());
        if(v2.find(i.first)==v2.end()){
            u+=i.second;
        }else{
            u+=max(i.second,v2[i.first]);
        }
    }
    printf("\n");
    for(auto&i:v2){
        printf("%s ", i.first.c_str());
        if(v1.find(i.first)==v1.end()){
            u+=i.second;
        }
    }
    printf("%d %d\n", n,u);
    if(u==0){
        return 65536;
    }
    return (int)((65536*(double)n)/u);
}