/*
	실버1
	백준 1697번 숨바꼭질
*/

#include <iostream>
#include <queue>

using namespace std;

bool arr[100001];

int main()
{
	int n, k;
	cin >> n >> k;

	int answer = abs(k - n); // 최대 횟수
	
	queue<pair<int, int>> q;
	q.push({n, 0});

	while(!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if(cur.second >= answer)
			continue;

		if(cur.first < 0 || cur.first > 100'000)
			continue;

		if(arr[cur.first])
			continue;

		arr[cur.first] = true;

		if(cur.first == k)
			answer = cur.second;

		q.push({ cur.first - 1, cur.second + 1 });
		q.push({ cur.first + 1, cur.second + 1 });
		q.push({ cur.first * 2, cur.second + 1 });
	}

	cout << answer;

	return 0;
}