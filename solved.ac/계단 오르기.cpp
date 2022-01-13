/*
	실버3
	백준 2579번 계단 오르기
*/

#include <iostream>

using namespace std;

int arr[301][3] = {{0, 0, 0}};

int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int input;
		cin >> input;

		arr[i][0] = max(arr[i-1][1], arr[i-1][2]);
		arr[i][1] = arr[i-1][0] + input;
		arr[i][2] = arr[i-1][1] + input;
	}

	cout << max(arr[n][1], arr[n][2]);
	
	return 0;
}