/*
	플레 5
	백준 10273번 고대 동굴 탐사
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
	int cave = -1;
	int cost;
	int max_value = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int n, e;
		cin >> n >> e;
		vector<int> value(n);
		vector<vector<Node>> routes(n);
		vector<Node> answer(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> value[i];
		}
		for (int i = 0; i < e; ++i)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			
			routes[--u].push_back({--v, cost});
		}

		stack<Node> s;
		s.push({ 0, 0, value[0] });
		while (!s.empty())
		{
			Node cur = s.top();
			s.pop();

			for (Node next : routes[cur.cave])
			{
				
			}
		}
	}

	return 0;
}