#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer="";
    string sum="";
    for(int k=0;k<s.length();k++){
        if(s[k]==' '){
            for(int j=0;j<sum.length();j++){
                if(j%2==0){
                    if(sum[j]>='a'&&sum[j]<='z'){
                        sum[j]=sum[j]-'a'+'A';
                    }
                }else{
                    if(sum[j]>='A'&&sum[j]<='Z'){
                        sum[j]=sum[j]-'A'+'a';
                    }
                }
            }
            answer+=sum+" ";
            sum="";
            continue;
        }
        sum+=s[k];
    }
    for(int j=0;j<sum.length();j++){
                if(j%2==0){
                    if(sum[j]>='a'&&sum[j]<='z'){
                        sum[j]=sum[j]-'a'+'A';
                    }
                }else{
                    if(sum[j]>='A'&&sum[j]<='Z'){
                        sum[j]=sum[j]-'A'+'a';
                    }
                }
            }
            answer+=sum+" ";
    answer.pop_back();
    return answer;
}