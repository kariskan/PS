#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string parse(long long n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    res+="0";
    reverse(res.begin(),res.end());
    return res;
}

long long parse2(string s){
    long long pow=1,res=0;
    for(int i=s.length()-1;i>=0;i--){
        res+=pow*(s[i]-'0');
        pow*=2;
    }
    return res;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();i++){
        string binary=parse(numbers[i]);
        string minBinary(binary.size(), '1');
        for(int j=0;j<binary.size();j++){
            string temp = binary;
            temp[j] = (1-(binary[j]-'0'))+'0';
            if(temp>binary&&minBinary>temp){
                minBinary=temp;
            }
        }
        for(int j=0;j<binary.size();j++){
            for(int k=j+1;k<binary.size();k++){
                string temp = binary;
                temp[j] = (1-(binary[j]-'0'))+'0';
                temp[k] = (1-(binary[k]-'0'))+'0';
                if(temp>binary&&minBinary>temp){
                    minBinary=temp;
                }
            }
        }
        answer.push_back(parse2(minBinary));
    }
    
    return answer;
}