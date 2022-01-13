/*
	브론즈2
	백준 2231번 분해합
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int answer = 0;
	for(int i = 1; i < n; ++i)
	{
		int tmp = i;
		int compare = i;

		while(tmp != 0)
		{
			compare += tmp % 10;
			tmp /= 10;
		}
		if(compare == n)
		{
			answer = i;
			break;
		}
	}
	cout << answer << endl;

	return 0;
}