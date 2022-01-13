/*
	실버3
	백준 2606번 바이러스
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool check[100] = {true, true, };

int main()
{
	int n, m;
	cin >> n >> m;

	multimap<int, int> map;
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		map.insert({a, b});
		map.insert({b, a});
	}

	queue<int> q;
	q.push(1);
	int count = 0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range = map.equal_range(cur);
		for(multimap<int, int>::iterator iter = range.first; iter != range.second; ++iter)
		{
			if(check[iter->second] == false)
			{
				++count;
				check[iter->second] = true;
				q.push(iter->second);
			}
		}
	}
	cout << count;

	return 0;
}