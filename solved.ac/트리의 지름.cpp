/*
	골드 4
	백준 1967번 트리의 지름
*/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Edge
{
	int dest;
	int weight;
};

multimap<int, Edge> edges;
int value[10000];

int dfs(int dest, int weight)
{
	int w1 = 0, w2 = 0;

	pair<multimap<int, Edge>::iterator, multimap<int, Edge>::iterator> range = edges.equal_range(dest);
	multimap<int, Edge>::iterator iter;
	for (iter = range.first; iter != range.second; ++iter)
	{
		int v = dfs(iter->second.dest, iter->second.weight);
		
		if (v > w1)
			swap(v, w1);
		w2 = max(v, w2);
	}

	value[dest] = w1 + w2;

	return w1 + weight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	for(int i = 1; i < n; ++i)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;

		edges.insert({ src, {dest, weight} });
	}

	dfs(1, 0);
	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, value[i]);
	}
	cout << answer;

	return 0;
}