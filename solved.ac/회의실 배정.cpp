/*
	실버2
	회의실 배정
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second == p2.second ? p1.first > p2.first : p1.second > p2.second;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	int answer = 0;
	pair<int, int> cur = {-1, -1};
	for(pair<int, int> p : v)
	{
		if(cur.first == -1 || cur.first >= p.second)
		{
			cur = p;
			++answer;
		}
		else if(cur.first <= p.first)
			cur = p;
	}
	cout << answer;

	return 0;
}