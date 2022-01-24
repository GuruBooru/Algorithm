/*
	실버 5
	백준 11660번 구간 합 구하기5
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr = vector<vector<int>>(n);
	vector<vector<int>> segment = vector<vector<int>>(n);

	for (int i = 0; i < n; ++i)
	{
		arr[i] = vector<int>(n);
		segment[i] = vector<int>(n);
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cin >> arr[row][col];

			segment[row][col] = arr[row][col];
			
			if (row != 0)
				segment[row][col] += segment[row - 1][col];

			if (col != 0)
				segment[row][col] += segment[row][col - 1];

			if (row != 0 && col != 0)
				segment[row][col] -= segment[row-1][col-1];

		}
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1; --x2; --y2;

		int answer = segment[x2][y2];
		--x1; --y1;
		if (y1 >= 0)
			answer -= segment[x2][y1];
		if (x1 >= 0)
			answer -= segment[x1][y2];
		if (x1 >= 0 && y1 >= 0)
			answer += segment[x1][y1];

		cout << answer << "\n";
	}

	return 0;
}