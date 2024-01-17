#include <string>
#include <vector>

using namespace std;

int a1[5]={1,2,3,4,5};
int a2[8]={2, 1, 2, 3, 2, 4, 2, 5};
int a3[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int a1Idx=0, a2Idx=0, a3Idx=0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int s1=0,s2=0,s3=0,maxScore=0;
    for(int i=0;i<answers.size();i++){
        if(answers[i]==a1[a1Idx]){
            s1++;
        }
        if(answers[i]==a2[a2Idx]){
            s2++;
        }
        if(answers[i]==a3[a3Idx]){
            s3++;
        }
        a1Idx=(a1Idx+1)%5;
        a2Idx=(a2Idx+1)%8; 
        a3Idx=(a3Idx+1)%10;
    }
    printf("%d%d%d\n", s1,s2,s3);
    maxScore=max(s1,max(s2,s3));
    if(maxScore==0){
        maxScore=-1;
    }
    if(s1==maxScore)answer.push_back(1);
    if(s2==maxScore)answer.push_back(2);
    if(s3==maxScore)answer.push_back(3);
    return answer;
}