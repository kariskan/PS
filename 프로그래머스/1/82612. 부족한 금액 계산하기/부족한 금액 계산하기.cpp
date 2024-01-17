#include <iostream>
using namespace std;

long long solution(int price, int money, int count) {
    long long answer = 0;
    for(int i=0;i<count;i++){
        answer+=(i+1)*price;
    }

    return max((long long)0, answer - money);
}