/*
	실버1
	백준 16928번 뱀과 사다리 게임
*/

#include <iostream>
#include <queue>

using namespace std;

int arr[101];
int num[101];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n + m; ++i)
	{
		int start, end;
		cin >> start >> end;

		arr[start] = end;
	}

	queue<pair<int, int>> q;
	q.push({1, 0});
	while(!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if(cur.first > 100)
			continue;
		if(cur.second >= num[cur.first] && num[cur.first] != 0)
			continue;

		num[cur.first] = cur.second;

		if(arr[cur.first] != 0)
			cur.first = arr[cur.first];
		cur.second++;

		q.push({ cur.first + 1, cur.second });
		q.push({ cur.first + 2, cur.second });
		q.push({ cur.first + 3, cur.second });
		q.push({ cur.first + 4, cur.second });
		q.push({ cur.first + 5, cur.second });
		q.push({ cur.first + 6, cur.second });
	}

	cout << num[100];

	return 0;
}