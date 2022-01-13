/*
	실버1
	백준 1389번 케빈 베이컨의 6단계 법칙
*/

#include <iostream>
#include <limits.h>

using namespace std;

int graph[100][100];

int main()
{

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
				graph[i][j] = 101;
		}
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				if(graph[j][k] > graph[j][i] + graph[k][i])
				{
					graph[j][k] = graph[j][i] + graph[k][i];
					graph[k][j] = graph[j][i] + graph[k][i];
				}
			}
		}
	}

	int answer = 0;
	int minValue = INT_MAX;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i != j)
				graph[i][i] += graph[i][j];
		}

		if(minValue > graph[i][i])
		{
			answer = i + 1;
			minValue = graph[i][i];
		}
	}

	cout << answer;

	return 0;
}