#include <string>
#include <vector>
using namespace std;

bool alphabet(char a){
    return a>='a'&&a<='z';
}

bool number(char a){
    return a>='0'&&a<='9';
}

string solution(string id) {
    for(int i=0;i<id.length();i++){
        if(id[i]>='A'&&id[i]<='Z'){
            id[i]=id[i]-'A'+'a';
        }
    }
    for(int i=0;i<id.length();i++){
        if(!alphabet(id[i])&&!number(id[i])&&id[i]!='-'&&id[i]!='_'&&id[i]!='.'){
            id.erase(id.begin() + i);
            i--;
        }
    }
    for(int i=0;i<id.length();i++){
        if(id[i]!='.'){
            continue;
        }
        int idx=i;
        while(idx<id.length()&&id[idx]=='.'){
            idx++;
        }
        if(idx-i>1){
            id.erase(id.begin()+i+1,id.begin()+idx);
        }
    }
    if(id[0]=='.'){
        id.erase(id.begin());
    }
    if(id[id.length()-1]=='.'){
        id.erase(id.end()-1);
    }
    if(id.empty()){
        id="a";
    }
    if(id.length()>=16){
        id=id.substr(0,15);
        if(id[id.length()-1]=='.'){
            id.erase(id.end()-1);
        }
    }
    if(id.length()<=2){
        while(id.length()<3){
            id+=id[id.length()-1];
        }
    }
    
    return id;
}