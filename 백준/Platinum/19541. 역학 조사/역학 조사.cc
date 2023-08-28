#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
vector<int> Meeting[MAX];
int visited[MAX]; // 주어진 최종 감염자 데이터
int initial[MAX]; // 초기 감염자 후보
int infected[MAX]; // 최종 감염자
bool answer = true;

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;
			Meeting[i].push_back(A);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> visited[i];
		infected[i] = visited[i]; // 최종 감염자의 정보를 저장
		initial[i] = visited[i]; // 초기 감염자 후보를 저장
	}
	// 모임을 역순으로 거슬러 올라간다.
	for (int i = (M - 1); i >= 0; i--) {
		bool Flag = true;
		for (int j = 0; j < Meeting[i].size(); j++) {
			int A = Meeting[i][j];
			if (visited[A] == 0) { // 해당 모임에서 최종 비감염자가 있는 경우
				// 해당 모임의 모든 인원들은 초기 감염자가 될 수 없다.
				Flag = false;
				break;
			}
		}
		if (!Flag) { // 최종 감염자가 한 명이라도 존재하지 않으면 모든 인원들은 초기 감염자가 아님
			for (int j = 0; j < Meeting[i].size(); j++) {
				int A = Meeting[i][j];
				initial[A] = 0;
				visited[A] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = initial[i]; // 남은 후보들을 초기감염자라고 가정한다.
	}
	// 모임을 시간 순서대로 거슬러 올라간다.
	for (int i = 0; i < M; i++) {
		bool Flag = false;
		for (int j = 0; j < Meeting[i].size(); j++) {
			int A = Meeting[i][j];
			if (visited[A] == 1) { // 해당 모임에서 초기 감염자 후보가 있는 경우
				Flag = true;
				break;
			}
		}
		if (Flag) { // 초기 감염자 후보가 한 명이라도 존재한다면 모임의 모든 사람이 감염된다(고 가정)
			for (int j = 0; j < Meeting[i].size(); j++) {
				int A = Meeting[i][j];
				visited[A] = 1;
			}
		}
	}
	// 확인한 감염 정보와 최종 감염자의 정보가 일치하지 않는다면 NO 출력
	for (int i = 1; i <= N; i++) {
		if (infected[i] != visited[i]) {
			answer = false;
			break;
		}
	}
	
	if (answer) {
		cout << "YES" << "\n";
		for (int i = 1; i <= N; i++) {
			cout << initial[i] << " ";
		}
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}