/*
	실버1
	백준 7569번 토마토
*/

#include <iostream>
#include <queue>

using namespace std;

int arr[100][100][100][2];

typedef struct point
{
	int height;
	int row;
	int col;
	int days = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, h;
	cin >> m >> n >> h;

	queue<point> q;
	for(int height = 0; height < h; ++height)
	{
		for(int row = 0; row < n; ++row)
		{
			for(int col = 0; col < m; ++col)
			{
				cin >> arr[height][row][col][0];
				arr[height][row][col][1] = 1000000;
				if (arr[height][row][col][0] == 1)
				{
					arr[height][row][col][1] = 0;
					q.push({ height, row, col + 1, 1 }); 
					q.push({ height, row, col - 1, 1 });
					q.push({ height, row + 1, col, 1 });
					q.push({ height, row - 1, col, 1 });
					q.push({ height + 1, row, col, 1 });
					q.push({ height - 1, row, col, 1 });
				}
					
			}
		}
	}

	while(!q.empty())
	{
		point cur = q.front();
		q.pop();

		if(((cur.height < 0) || (cur.height >= h)) || ((cur.row < 0) || (cur.row >= n)) || ((cur.col < 0) || (cur.col >= m)))
			continue;
		if(arr[cur.height][cur.row][cur.col][0] != 0)
			continue;
		if(cur.days >= arr[cur.height][cur.row][cur.col][1])
			continue;

		arr[cur.height][cur.row][cur.col][0] = 1;
		arr[cur.height][cur.row][cur.col][1] = cur.days;

		cur.days += 1;
		q.push({ cur.height, cur.row, cur.col + 1, cur.days });
		q.push({ cur.height, cur.row, cur.col - 1, cur.days });
		q.push({ cur.height, cur.row + 1, cur.col, cur.days });
		q.push({ cur.height, cur.row - 1, cur.col, cur.days });
		q.push({ cur.height + 1, cur.row, cur.col, cur.days });
		q.push({ cur.height - 1, cur.row, cur.col, cur.days });
	}

	int answer = 0;
	for (int height = 0; height < h; ++height)
	{
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < m; ++col)
			{
				if(arr[height][row][col][0] == 0)
				{
					answer = -1;
					break;
				}

				if(arr[height][row][col][0] == 1)
				{
					answer = max(answer, arr[height][row][col][1]);
				}
			}
			if(answer == -1)
				break;
		}
		if(answer == -1)
			break;
	}
	cout << answer;

	return 0;
}