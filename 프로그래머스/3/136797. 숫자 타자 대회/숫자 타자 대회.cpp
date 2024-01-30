#include <string>
#include <vector>

using namespace std;

// 왼손이 i, 오른손이 j에 있고, k번째 숫자를 누를 때 최솟값
int dp[100001][10][10];
pair<int,int> pos[10]={
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

int getDis(int thumb, int number){
    pair<int,int> thumbPos=pos[thumb];
    pair<int,int> numberPos=pos[number];

    if(thumbPos.first==numberPos.first&&thumbPos.second==numberPos.second){
        return 1;
    }else if(thumbPos.first==numberPos.first){
        return abs(thumbPos.second-numberPos.second)*2;
    }else if(thumbPos.second==numberPos.second){
        return abs(thumbPos.first-numberPos.first)*2;
    }else{
        int mi=min(abs(numberPos.first-thumbPos.first),abs(numberPos.second-thumbPos.second));
        int ma=max(abs(numberPos.first-thumbPos.first),abs(numberPos.second-thumbPos.second));
        return (ma-mi)*2+mi*3;
    }
}

string numbers;

int go(int left, int right, int idx){
    if(idx>=numbers.length()){
        return 0;
    }
    if(dp[idx][left][right]){
        return dp[idx][left][right];
    }
    if(left==numbers[idx]-'0'||right==numbers[idx]-'0'){
        return dp[idx][left][right]=1+go(left,right,idx+1);
    }
    if(left==1&&right==5&&idx==4){
        int p=1;
    }
    int l = getDis(left,numbers[idx]-'0')+go(numbers[idx]-'0',right,idx+1);
    int r = getDis(right,numbers[idx]-'0')+go(left,numbers[idx]-'0',idx+1);
    return dp[idx][left][right]=min(l,r);
}

int solution(string numbers) {
    ::numbers=numbers;
    return go(4,6,0);
}