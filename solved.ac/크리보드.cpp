/*
	골드5
	백준 11058번 크리보드
*/

#include <iostream>

using namespace std;

long long c[101] = {0, 1, 2, 3, 4, 5, 6, };
long long buffer;

int main()
{
	int n;
	cin >> n;
	for (int i = 6; i <= n; ++i)
	{
		c[i] = max(c[i-1] + 1, max(c[i-3] * 2, max(c[i - 4] * 3, c[i-5] * 4)));
	}

	cout << c[n];

	return 0;
}