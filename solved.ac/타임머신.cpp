/*
	골드4
	백준 11657번 타임머신
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr auto INF = 5000001;;
struct Edge
{
	int s;
	int d;
	long long w;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges(m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;
		edges[i] = { a, b, c };
	}

	vector<long long> distance(n + 1);
	bool minus_flag = false;

	for (int i = 0; i < n + 1; ++i)
		distance[i] = INF;

	distance[1] = 0;
	for (int i = 1; i < m; ++i)
	{
		for (auto e : edges)
		{
			if (distance[e.s] == INF)
				continue;

			distance[e.d] = min(distance[e.d], distance[e.s] + e.w);
		}
	}
	for (auto e : edges)
	{
		if (distance[e.d] > distance[e.s] + e.w)
			minus_flag = true;
	}

	if (minus_flag)
		cout << -1 << "\n";
	else
	{
		for (int i = 2; i < n + 1; ++i)
		{
			if (distance[i] == INF)
				cout << distance[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}	

	return 0;
}