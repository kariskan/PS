#include <iostream>
using namespace std;

int main()
{

	for (int a = 2; a <= 100; a++)
	{
		for (int b = 2; b <= 100; b++)
		{
			for (int c = b + 1; c <= 100; c++)
			{
				for (int d = c + 1; d <= 100; d++)
				{
					if (b * b * b + c * c * c + d * d * d == a * a * a)
					{
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
					}
				}
			}
		}
	}
}