/*
	골드 3
	백준 1516번 게임 개발
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tech_tree;
vector<int> time_arr;
vector<bool> not_end_tech;

int dfs(int cur_node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	tech_tree = vector<vector<int>>(n + 1);
	time_arr = vector<int>(n + 1);
	not_end_tech = vector<bool>(n + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		int t, pre_tech;
		cin >> t >> pre_tech;

		tech_tree[i].push_back(t);
		
		while (pre_tech != -1)
		{
			tech_tree[i].push_back(pre_tech);
			not_end_tech[pre_tech] = true;
			cin >> pre_tech;
		}
	}

	queue<int> end_tech;
	for (int i = 1; i <= n; ++i)
	{
		if (!not_end_tech[i])
			end_tech.push(i);
	}

	while (!end_tech.empty())
	{
		int root = end_tech.front();
		end_tech.pop();

		dfs(root);
	}
	for (int i = 1; i < time_arr.size(); ++i)
	{
		cout << time_arr[i] << "\n";
	}

	return 0;
}

int dfs(int cur_node)
{
	int value = 0;

	for (int i = 1; i < tech_tree[cur_node].size(); ++i)
	{
		int next = tech_tree[cur_node][i];

		if (time_arr[next])
			value = max(time_arr[next], value);
		else
			value = max(dfs(next), value);
	}
	time_arr[cur_node] = value + tech_tree[cur_node][0];

	return time_arr[cur_node];
}