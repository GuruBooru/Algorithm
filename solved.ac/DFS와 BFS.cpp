/*
	실버2
	백준 1260번 DFS와 BFS
*/

#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool stackCheck[1001][2];
bool queueCheck[1001][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	map<int, vector<int>> g;
	cin >> n >> m >> v;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	stack<int> s;
	s.push(v);

	while(!s.empty())
	{
		int cur = s.top();
		s.pop();
		stackCheck[cur][0] = true;

		if(!stackCheck[cur][1])
		{
			if (cur != v)
				cout << " ";
			cout << cur;
			stackCheck[cur][1] = true;
		}
		
		sort(g[cur].begin(), g[cur].end(), greater<int>());
		for(int i : g[cur])
		{
			if(!stackCheck[i][0])
			{
				s.push(i);
			}
		}
	}
	cout << "\n";

	queue<int> q;
	q.push(v);
	queueCheck[v][0] = true;

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (!queueCheck[cur][1])
		{
			if (cur != v)
				cout << " ";
			cout << cur;
			queueCheck[cur][1] = true;
		}

		sort(g[cur].begin(), g[cur].end());
		for (int i : g[cur])
		{
			if (!queueCheck[i][0])
			{
				q.push(i);
				queueCheck[i][0] = true;
			}
		}
	}

	return 0;
}