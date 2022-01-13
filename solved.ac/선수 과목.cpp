/*
	골드 5
	백준 14567번 선수 과목
*/

#include <iostream>
#include <map>

using namespace std;

int answer[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		answer[i] = 1;
	}
	multimap<int, int> course;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		course.insert({ a, b });
	}

	for (int i = 1; i <= n; ++i)
	{
		pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range = course.equal_range(i);
		multimap<int, int>::iterator iter;
		for (iter = range.first; iter != range.second; ++iter)
		{
			int a = iter->first;
			int b = iter->second;

			answer[b] = min(answer[a] + 1, answer[b]);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << answer[i] << " ";
	}

	return 0;
}