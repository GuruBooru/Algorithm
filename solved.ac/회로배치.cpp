/*
	플레티넘 4
	백준 2645번 회로배치
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
	int dist;
	int row;
	int col;

	bool operator<(const Node& n) const
	{
		if (dist != n.dist) return dist > n.dist;
		else if (col != n.col) return col < n.col;
		else return row < n.row;
	}
};

int n;
pair<int, int> nodeA, nodeB;
int k;

bool circuit[51][51];
pair<int, int> start;
void drawCircuit(int next_row, int next_col);

#define MAX_NUM 10000
Node dist[51][51];
int dir_row[4] = { 0, 1, 0, -1 };
int dir_col[4] = { 1, 0, -1, 0 };

stack<pair<int, int>> findPath(pair<int, int> end);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n
		>> nodeA.first >> nodeA.second >> nodeB.first >> nodeB.second
		>> k;
	int circuitNum;
	cin >> circuitNum;
	for (int i = 0; i < circuitNum; ++i)
	{
		int cornerNum;
		cin >> cornerNum;
		start.first = 0; start.second = 0;
		for (int j = 0; j < cornerNum; ++j)
		{
			int next_row, next_col;
			cin >> next_row >> next_col;
			if (start.first == 0 && start.second == 0)
				start = { next_row, next_col };
			else
				drawCircuit(next_row, next_col);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			dist[i][j].dist = MAX_NUM;
	}
	dist[nodeA.first][nodeA.second].dist = 1;
	priority_queue<Node> q;
	q.push({ 1, nodeA.first, nodeA.second });
	while (!q.empty())
	{
		Node cur_node = q.top();
		q.pop();

		if (dist[cur_node.row][cur_node.col].dist < cur_node.dist)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int next_row = cur_node.row + dir_row[i];
			int next_col = cur_node.col + dir_col[i];

			if (!(0 < next_row && next_row <= n) || !(0 < next_col && next_col <= n))
				continue;

			int next_dist = circuit[next_row][next_col] ? cur_node.dist + k : cur_node.dist + 1;
			if (next_dist >= dist[next_row][next_col].dist)
				continue;

			dist[next_row][next_col].dist = next_dist;
			dist[next_row][next_col].row = cur_node.row;
			dist[next_row][next_col].col = cur_node.col;

			q.push({ next_dist, next_row, next_col });
		}
	}
	stack<pair<int, int>> path = findPath(nodeB);

	cout << dist[nodeB.first][nodeB.second].dist << "\n";
	cout << path.size() << " ";
	while (!path.empty())
	{
		cout << path.top().first << " " << path.top().second << " ";
		path.pop();
	}

	return 0;
}

void drawCircuit(int next_row, int next_col)
{
	int fix_index, dynamic_start, dynamic_end;
	bool row_fix = true;
	if (start.first == next_row)
	{
		fix_index = start.first;
		dynamic_start = min(start.second, next_col);
		dynamic_end = max(start.second, next_col);
	}
	else
	{
		fix_index = start.second;
		row_fix = false;
		dynamic_start = min(start.first, next_row);
		dynamic_end = max(start.first, next_row);
	}

	for (int i = dynamic_start; i <= dynamic_end; ++i)
	{
		if (row_fix)
			circuit[fix_index][i] = true;
		else
			circuit[i][fix_index] = true;
	}

	start = { next_row, next_col };
}
stack<pair<int, int>> findPath(pair<int, int> end)
{
	stack<pair<int, int>> path;
	pair<int, int> cur_node = end;
	path.push(cur_node);
	
	pair<int, int> pre_node = { dist[cur_node.first][cur_node.second].row, dist[cur_node.first][cur_node.second].col };
	while (pre_node != nodeA)
	{
		pair<int, int> direct = { cur_node.first - pre_node.first, cur_node.second - pre_node.second };

		cur_node = pre_node;
		pre_node = { dist[cur_node.first][cur_node.second].row, dist[cur_node.first][cur_node.second].col };

		pair<int, int> pre_direct = { cur_node.first - pre_node.first, cur_node.second - pre_node.second };
		if (direct != pre_direct)
			path.push(cur_node);
	}
	path.push(pre_node);

	return path;
}