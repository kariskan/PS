#include <iostream>
using namespace std;

int main()
{
	int h, w, n, m;
	cin >> h >> w >> n >> m;

	cout << ((h + n) / (n + 1)) * ((w + m) / (m + 1));
}