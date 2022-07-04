#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int a[10] = {0,};
    for(int n:numbers)a[n] = 1;
    for(int i=1;i<=9;i++)if(!a[i])answer+=i;
    return answer;
}