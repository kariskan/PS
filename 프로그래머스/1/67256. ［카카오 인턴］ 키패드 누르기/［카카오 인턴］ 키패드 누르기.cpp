#include <string>
#include <vector>

using namespace std;

pair<int, int> pos[10]={
    {3,1},
    {0,0},
    {0,1},
    {0,2},
    {1,0},
    {1,1},
    {1,2},
    {2,0},
    {2,1},
    {2,2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> l={3,0}, r={3,2};
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            answer+="L";
            l = pos[numbers[i]];
        }else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            answer+="R";
            r = pos[numbers[i]];
        }else{
            int lDis = abs(pos[numbers[i]].first-l.first) + abs(pos[numbers[i]].second - l.second);
            int rDis = abs(pos[numbers[i]].first-r.first) + abs(pos[numbers[i]].second - r.second);
            if (lDis<rDis||(lDis==rDis&&hand=="left")){
                answer+="L";
                l=pos[numbers[i]];
            }else {
                answer+="R";
                r=pos[numbers[i]];
            }
        }
    }
    
    
    return answer;
}