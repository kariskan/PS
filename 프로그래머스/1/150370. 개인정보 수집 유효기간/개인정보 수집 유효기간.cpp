#include <string>
#include <vector>
#include <sstream>
using namespace std;

int dayOfYear=12*28;

int parse(string today) {
    vector<string> v;
    stringstream ss(today);
    string temp;
    while(getline(ss,temp,'.')){
        v.push_back(temp);
    }
    return (stoi(v[0])-1)*dayOfYear+(stoi(v[1])-1)*28+stoi(v[2]);
}

vector<string> parse2(string s){
    vector<string> v;
    stringstream ss(s);
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int t=0;t<privacies.size();t++){
        string privacy=privacies[t];
        vector<string> v=parse2(privacy);
        int targetDay = parse(v[0]);
        char targetPrivacy = v[1][0];
        int month;
        for(int i=0;i<terms.size();i++){
            vector<string> v2=parse2(terms[i]);
            if(v2[0][0]==targetPrivacy){
                printf("%d %d\n", parse(today), targetDay+28*stoi(v2[1]));
                if(parse(today)>=targetDay+28*stoi(v2[1])){
                    answer.push_back(t+1);
                }
            }
        }
    }
    
    return answer;
}