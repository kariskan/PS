#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, int> score;
pair<char, char> a[4]={{'R','T'},{'C','F'},{'J','M'},{'A','N'}};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0;i<survey.size();i++){
        if(choices[i]>4){
            score[survey[i][1]]+=abs(choices[i]-4);
        }else if(choices[i]<4){
            score[survey[i][0]]+=abs(choices[i]-4);
        }
    }
    for(int i=0;i<4;i++){
        if(score[a[i].first]>=score[a[i].second]){
            answer+=a[i].first;
        }else{
            answer+=a[i].second;
        }
    }
    return answer;
}