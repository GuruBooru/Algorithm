/*
	실버3
	백준 1463번 1로 만들기
*/

#include <iostream>
#include <limits.h>

using namespace std;

int arr[1'000'001];

int main()
{
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		int value = INT_MAX;
		if(i % 3 == 0)
			value = min(value, arr[i / 3]);
		if(i % 2 == 0)
			value = min(value, arr[i / 2]);
		value = min(value, arr[i - 1]);
		arr[i] = value + 1;
	}
	cout << arr[n];

	return 0;
}