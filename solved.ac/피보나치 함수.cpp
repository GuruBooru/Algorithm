/*
	실버3
	백준 1003번 피보나치 함수
*/

#include <iostream>

using namespace std;

long long arr[41][2] = {{1, 0}, {0, 1},};

int main()
{
	for(int i = 2; i < 41; ++i)
	{
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cout << arr[n][0] << " " << arr[n][1] << "\n";
	}

	return 0;
}