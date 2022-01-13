/*
	실버1
	백준 7576번 토마토
*/

#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];

typedef struct point
{
	int row;
	int col;
	int days;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> m >> n;

	queue<point> q;
	bool zero = false;
	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < m; ++col)
		{
			cin >> arr[row][col];

			if(arr[row][col] == 1)
			{
				q.push({ row, col + 1, 1 });
				q.push({ row, col - 1, 1 });
				q.push({ row + 1, col, 1 });
				q.push({ row - 1, col, 1 });
			}
			if(arr[row][col] == 0)
				zero = true;
		}
	}

	while(!q.empty())
	{
		point cur = q.front();
		q.pop();

		if((cur.row < 0 || cur.row >= n) || (cur.col < 0 || cur.col >= m))
			continue;
		if(arr[cur.row][cur.col] == -1)
			continue;
		if(cur.days >= arr[cur.row][cur.col] && arr[cur.row][cur.col] != 0)
			continue;

		arr[cur.row][cur.col] = cur.days;
		++cur.days;

		q.push({ cur.row, cur.col + 1, cur.days });
		q.push({ cur.row, cur.col - 1, cur.days });
		q.push({ cur.row + 1, cur.col, cur.days });
		q.push({ cur.row - 1, cur.col, cur.days });
	}

	int answer = 0;
	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < m; ++col)
		{
			if(arr[row][col] == 0)
			{
				answer = -1;
				break;
			}
			else if(arr[row][col] != -1)
			{
				answer = max(answer, arr[row][col]);
			}
		}
		if(answer == -1)
			break;
	}

	if(!zero)
		answer = 0;
	cout << answer;

	return 0;
}