/*
	실버2
	백준 11724번 연결 요소의 개수
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool check[1001];

int main()
{
	int n, m;
	cin >> n >> m;

	multimap<int, int> map;

	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		map.insert({u, v});
		map.insert({v, u});
	}

	int answer = 0;
	if(m != 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (!check[i])
			{
				++answer;
				queue<int> q;
				q.push(i);
				check[i] = true;

				while (!q.empty())
				{
					int cur = q.front();
					q.pop();

					pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range = map.equal_range(cur);
					multimap<int, int>::iterator iter;
					for (iter = range.first; iter != range.second; ++iter)
					{
						if (!check[iter->second])
						{
							q.push(iter->second);
							check[iter->second] = true;
						}
					}
				}
			}
		}
	}
	

	cout << answer;

	return 0;
}