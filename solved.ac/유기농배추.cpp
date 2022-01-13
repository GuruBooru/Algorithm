/*
	실버2
	백준 1012번 유기농 배추
*/

#include <iostream>
#include <queue>

using namespace std;

int map[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int m, n, k;
		cin >> m >> n >> k;

		for(int j = 0; j < k; ++j)
		{
			int row, col;
			cin >> col >> row;
			map[row][col] = 1;
		}

		int answer = 0;
		for(int row = 0; row < n; ++row)
		{
			for(int col = 0; col < m; ++col)
			{
				if(map[row][col] != 0)
				{
					queue<pair<int, int>> q;
					q.push({row, col});

					while(!q.empty())
					{
						pair<int, int> cur = q.front();
						q.pop();

						if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m)
							continue;

						if(map[cur.first][cur.second] != 0)
						{
							map[cur.first][cur.second] = 0;
							q.push({ cur.first - 1, cur.second });
							q.push({ cur.first + 1, cur.second });
							q.push({ cur.first, cur.second - 1 });
							q.push({ cur.first, cur.second + 1 });
						}
					}
					++answer;
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}