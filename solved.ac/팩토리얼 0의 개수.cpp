/*
	실버3
	백준 1676번 팩토리얼 0의 개수
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int count2 = 0;
	int count5 = 0;
	int p = 1;
	for(int i = 1; i < n + 1; ++i)
	{
		int tmp2 = i;
		int tmp5 = i;
		while(tmp2 % 2 == 0)
		{
			++count2;
			tmp2 /= 2;
		}

		while(tmp5 % 5 == 0)
		{
			++count5;
			tmp5 /= 5;
		}
	}
	int count = count2 < count5 ? count2 : count5;
	cout << count;

	return 0;
}