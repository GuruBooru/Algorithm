/*
	브론즈2
	백준 2775번 부녀회장이 될테야
*/

#include <iostream>

using namespace std;

long long arr[15][14] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, };

int main()
{
	for(int i = 1; i < 15; ++i)
	{
		for(int j = 0; j < 14; ++j)
		{
			if(j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int k, n;	
		cin >> k >> n;
		cout << arr[k][n-1] <<"\n";
	}

	return 0;
}