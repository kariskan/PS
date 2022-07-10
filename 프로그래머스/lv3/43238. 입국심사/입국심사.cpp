#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = -1;
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * 1000000000;
    while(left<=right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(int i=0;i<times.size();i++){
            sum += mid / times[i];
        }
        
        if(sum >= n) {
            right = mid - 1;
            if(answer == -1 || answer > mid) {
                answer = mid;
            }
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}