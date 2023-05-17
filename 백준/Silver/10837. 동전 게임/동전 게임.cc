#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;

	int C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		int M, N;
		cin >> M >> N;

		// 영희와 동수 점수가 같다면 100% 가능
		if (M - N == 0)
		{
			cout << 1 << "\n";

			continue;
		}

		int remainGames = K - max(M, N);
		int diff = abs(M - N);

		// 영희 점수가 더 높을 경우
		if (M > N)
		{
			if (diff - remainGames <= 2)
			{
				cout << 1 << "\n";

				continue;
			}

			cout << 0 << "\n";

			continue;
		}

		// 동수 점수가 더 높을 경우
		if (diff - remainGames <= 1)
		{
			cout << 1 << "\n";

			continue;
		}

		cout << 0 << "\n";
	}

	return 0;
}