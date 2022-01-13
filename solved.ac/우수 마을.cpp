/*
	골드 1
	백준 1949번 우수 마을
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> population;
vector<vector<int>> edges;
vector<int> answer[2];
vector<bool> visited;

int find_next_value(int cur_town);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	population = vector<int>(n);
	edges = vector<vector<int>>(n);
	answer[0] = vector<int>(n);		// 내가 우수마을일 때
	answer[1] = vector<int>(n);		// 내가 우수마을이 아닐때
	visited = vector<bool>(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> population[i];
	}

	while (--n)
	{
		int u, v;
		cin >> u >> v;
		edges[--u].push_back(--v);
		edges[v].push_back(u);
	}

	find_next_value(0);
	cout << max(answer[0][0], answer[1][0]);

	return 0;
}

int find_next_value(int cur_town)
{
	visited[cur_town] = true;
	int next_value = 0;
	int nextnext_value = 0;

	for (int next : edges[cur_town])
	{
		if (visited[next])
			continue;

		if (answer[0][next] < population[cur_town] + find_next_value(next))
			nextnext_value += answer[1][next];
		
		next_value += max(answer[0][next], answer[1][next]);
	}
	answer[0][cur_town] = nextnext_value + population[cur_town];
	answer[1][cur_town] = next_value;

	return answer[0][cur_town];
}