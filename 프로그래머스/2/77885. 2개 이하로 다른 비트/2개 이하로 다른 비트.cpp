#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string toBinary(long long n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
long long toLL(string b){
    long long p=1;
    long long res=0;
    for(int i=b.length()-1;i>=0;i--){
        res+=p*(b[i]-'0');
        p*=2;
    }
    return res;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0;i<numbers.size();i++){
        string b="0" + toBinary(numbers[i]);
        for(int j=0;j<b.length();j++){
            string temp=b;
            temp[j]=(1-(temp[j]-'0'))+'0';
            if(b<temp){
                if(answer.size()==i){
                    answer.push_back(toLL(temp));
                }else if(answer[answer.size()-1]>toLL(temp)){
                    answer.back()=toLL(temp);
                }
            }
        }
        for(int j=0;j<b.length();j++){
            for(int k=j+1;k<b.length();k++){
                string temp=b;
                temp[j]=(1-(temp[j]-'0'))+'0';
                temp[k]=(1-(temp[k]-'0'))+'0';
                if(b<temp){
                    if(answer.size()==i){
                        answer.push_back(toLL(temp));
                    }else if(answer[answer.size()-1]>toLL(temp)){
                        answer.back()=toLL(temp);
                    }
                }
            }
        }
    }
    return answer;
}