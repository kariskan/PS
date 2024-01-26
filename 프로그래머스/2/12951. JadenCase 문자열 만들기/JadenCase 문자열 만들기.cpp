#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            if(!temp.empty()){
                if(temp[0]>='a'&&temp[0]<='z'){
                    temp[0]=temp[0]-'a'+'A';
                }
                for(int j=1;j<(int)temp.length();j++){
                    if(temp[j]>='A'&&temp[j]<='Z'){
                        temp[j]=temp[j]-'A'+'a';
                    }
                }
            }
            answer+=temp+" ";
            temp="";
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()){
                if(temp[0]>='a'&&temp[0]<='z'){
                    temp[0]=temp[0]-'a'+'A';
                }
                for(int j=1;j<(int)temp.length();j++){
                    if(temp[j]>='A'&&temp[j]<='Z'){
                        temp[j]=temp[j]-'A'+'a';
                    }
                }
            }
            answer+=temp;
    return answer;
}