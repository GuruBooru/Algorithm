/*
	실버1
	백준 2667번 단지 번호 붙이기
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char arr[25][25];

int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> arr[i];


	vector<int> answer;
	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			if(arr[row][col] != '1')
				continue;

			int value = 0;
			queue<pair<int, int>> q;
			q.push({row, col});

			while(!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				if(cur.first < 0 || cur.first == n)
					continue;
				if(cur.second < 0 || cur.second == n)
					continue;
				if(arr[cur.first][cur.second] == '0')
					continue;

				arr[cur.first][cur.second] = '0';
				++value;

				q.push({ cur.first, cur.second + 1 });
				q.push({ cur.first, cur.second - 1 });
				q.push({ cur.first + 1, cur.second });
				q.push({ cur.first - 1, cur.second });
			}
			answer.push_back(value);
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for(int i : answer)
	{
		cout << i << "\n";
	}

	return 0;
}