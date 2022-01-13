/*
	실버1
	백준 2178번 미로 탐색
*/

#include <iostream>
#include <queue>

using namespace std;

#define MAXVALUE 10000

char arr[100][100];

typedef struct data
{
	int value;
	int row;
	int col;
}Data;

int main()
{
	int n, m;
	cin >> n >> m;

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < m; ++col)
		{
			cin >> arr[row][col];
		}
	}

	int answer = MAXVALUE;
	queue<Data> q;
	q.push({1, 0, 0});
	while(!q.empty())
	{
		Data cur = q.front();
		q.pop();

		if(cur.row < 0 || cur.row >= n)
			continue;
		if(cur.col < 0 || cur.col >= m)
			continue;
		if(cur.value >= answer)
			continue;
		if(arr[cur.row][cur.col] == '0')
			continue;

		if (cur.row == n - 1 && cur.col == m - 1)
			answer = cur.value;

		arr[cur.row][cur.col] = '0';

		q.push({ cur.value + 1, cur.row, cur.col + 1 });
		q.push({ cur.value + 1, cur.row, cur.col - 1 });
		q.push({ cur.value + 1, cur.row + 1, cur.col });
		q.push({ cur.value + 1, cur.row - 1, cur.col });
	}

	cout << answer;

	return 0;
}