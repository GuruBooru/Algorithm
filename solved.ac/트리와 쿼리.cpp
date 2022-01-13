/*
	골드 5
	백준 15681번 트리와 쿼리
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> answer;
vector<bool> visited;
int findAnswer(int cur_node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	graph = vector<vector<int>>(n + 1);
	answer = vector<int>(n + 1);
	visited = vector<bool>(n + 1);
	for (int i = 1; i <= n; ++i)
		answer[i] = 1;
	while (--n)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[r] = true;
	findAnswer(r);

	while (q--)
	{
		int u;
		cin >> u;

		cout << answer[u] << "\n";
	}

	return 0;
}

int findAnswer(int cur_node)
{
	int sub_tree = 0;
	for (int next : graph[cur_node])
	{
		if (visited[next])
			continue;

		visited[next] = true;
		sub_tree += findAnswer(next);
	}
	answer[cur_node] += sub_tree;
	return answer[cur_node];
}