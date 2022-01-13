/*
	실버 5
	백준 11651번 좌표 정렬하기 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		v[i] = {x, y};
	}
	sort(v.begin(), v.end(), compare);

	for(pair<int, int> p : v)
	{
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}