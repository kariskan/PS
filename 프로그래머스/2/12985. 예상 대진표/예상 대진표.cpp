#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    if(a>b){
        swap(a,b);
    }
    int answer=1;
    while(a%2!=1||b-a!=1){
        a=(a+1)/2;
        b=(b+1)/2;
        answer++;
    }
    return answer;
}