#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> foods, food;
int solution(vector<int> food_times, long long k) {
	int answer = 0;
	long long size = food_times.size();
	for (int i = 0; i < size; i++)food.push_back((long long)food_times[i]);
	foods = food;
	sort(foods.begin(), foods.end());
	long long sum = 0;
	long long prevCnt = 0;
	long long minFood = 0;
	for (int i = 0; i < size; i++) {

		if (sum + (long long)(foods[i] - minFood) * (long long)(size - prevCnt) <= k) {
			sum += (long long)(foods[i] - minFood) * (long long)(size - prevCnt);
			minFood = foods[i];
			prevCnt++;
		}
		else {
			k -= sum;
			for (int j = 0; j < size; j++) {
				if (food[j] < minFood) {
					food[j] = 0;
				}
				else {
					food[j] -= minFood;
				}
			}
			break;
		}
	}
	if (prevCnt == size)return -1;
	for (int i = 0; i < size; i++) {
		if (food[i] == 0) {
			continue;
		}
		else {
			food[i] -= (k / (size - prevCnt));
		}
	}
	k %= (size - prevCnt);
	k++;
	long long j = 0;
	for (int i = 0; i < size && k; i++) {
		j++;
		if (food[i] == 0) {
			continue;
		}
		else {
			k--;
		}
		if (!k) {
			if (j == size && food[j - 1] == 0)answer = -1;
			else answer = j;
			break;
		}
	}
	return answer;
}