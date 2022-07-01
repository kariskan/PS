#include <iostream>
using namespace std;

int main() {
	long long hpY, atkY, hpM, atkM;
	cin >> hpY >> atkY >> hpM >> atkM;
	long long p, s;
	cin >> p >> s;
	long long yDeadCnt, mDeadCnt;
	if (hpY % atkM == 0) yDeadCnt = hpY / atkM;
	else yDeadCnt = hpY / atkM + 1;

	long long temp = hpM - ((hpM / atkY) * atkY);
	if ((temp >= 1 && temp <= p) || (temp + atkY >= 1 && temp + atkY <= p) || (temp - atkY >= 1 && temp - atkY <= p)
		|| (temp + 2 * atkY >= 1 && temp + 2 * atkY <= p) || (temp - 2 * atkY >= 1 && temp - 2 * atkY <= p)) {
		hpM += s;
	}

	if (hpM % atkY == 0)mDeadCnt = hpM / atkY;
	else mDeadCnt = hpM / atkY + 1;

	if (yDeadCnt >= mDeadCnt)cout << "Victory!";
	else cout << "gg";
}