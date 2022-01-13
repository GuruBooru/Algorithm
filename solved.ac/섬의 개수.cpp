/*
	실버 2
	백준 4963번 섬의 개수
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> direct[8] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h;
	cin >> w >> h;

	while (w != 0 && h != 0)
	{
		vector<vector<int>> map(h);
		vector<vector<bool>> visit(h);
		for (int row = 0; row < h; ++row)
		{
			map[row] = vector<int>(w);
			visit[row] = vector<bool>(w);
		}
		for (int row = 0; row < h; ++row)
		{
			for (int col = 0; col < w; ++col)
			{
				cin >> map[row][col];
				if (map[row][col])
					visit[row][col] = true;
			}
			
		}

		int answer = 0;
		for (int row = 0; row < h; ++row)
		{
			for (int col = 0; col < w; ++col)
			{
				if (!map[row][col])
					continue;

				queue <pair<int, int>> q;

				q.push({ row, col });
				while (!q.empty())
				{
					pair<int, int> cur_p = q.front();
					map[cur_p.first][cur_p.second] = 0;
					q.pop();

					for (pair<int, int> d : direct)
					{
						pair<int, int> next_p = { cur_p.first + d.first, cur_p.second + d.second };
						if (!(0 <= next_p.first && next_p.first < h) || !(0 <= next_p.second && next_p.second < w))
							continue;

						if (!map[next_p.first][next_p.second])
							continue;

						if (!visit[next_p.first][next_p.second])
							continue;

						visit[next_p.first][next_p.second] = false;
						q.push(next_p);
					}
				}
				++answer;
			}
		}
		cout << answer << "\n";

		cin >> w >> h;
	}

	return 0;
}