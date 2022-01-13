/*
	실버2
	백준 14494번 다이나믹이 뭐예요?
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<long long>> arr(n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = vector<long long>(m);
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			if (row == 0 || col == 0)
				arr[row][col] = 1;
			else
				arr[row][col] = (arr[row - 1][col] + arr[row][col - 1] + arr[row - 1][col - 1]) % 1'000'000'007;
		} 
	}
	cout << arr[n - 1][m - 1];

	return 0;
}