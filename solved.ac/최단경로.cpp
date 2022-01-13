/*
	골드5
	백준 1753번 최단경로
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

#define MAX_NUM 10e6

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;

	vector<vector<pair<int,int>>> g(v + 1);
	for (int i = 0; i < e; ++i)
	{
		int src, dest, w;
		cin >> src >> dest >> w;
		g[src].push_back({ w, dest });
	}

	vector<int> distance(v + 1);
	for (int i = 1; i <= v; ++i)
	{
		distance[i] = MAX_NUM;
	}

	distance[k] = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0, k });
	while (!q.empty())
	{
		int cur_node = q.top().second;
		int d = -q.top().first;
		q.pop();

		if (distance[cur_node] < d)
			continue;

		for (int i = 0; i < g[cur_node].size(); ++i)
		{
			int next_node = g[cur_node][i].second;
			int next_distance = g[cur_node][i].first + d;

			if (next_distance >= distance[next_node])
				continue;

			distance[next_node] = next_distance;
			q.push({ -next_distance, next_node });
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		if (distance[i] == MAX_NUM)
			cout << "INF\n";
		else
			cout << distance[i] << "\n";
	}

	return 0;
}