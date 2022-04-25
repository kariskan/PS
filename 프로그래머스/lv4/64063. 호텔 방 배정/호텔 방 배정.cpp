#include <string>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
unordered_map<long long, long long> room;
ll Find(ll num) {
	if (room[num] == 0) {
		return num;
	}
	return room[num] = Find(room[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (ll num = 0; num < room_number.size(); num++) {
		ll find = Find(room_number[num]);
		room[find] = find + 1;
		answer.push_back(find);
	}
	return answer;
}