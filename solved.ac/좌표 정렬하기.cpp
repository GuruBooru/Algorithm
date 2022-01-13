/*
	실버5
	백준 11650번 - 좌표 정렬하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<pair<int, int>> v;

	cin >> n;
	v.reserve(n);

	for(int i = 0; i < n; ++i)
	{
		pair<int, int> input;

		cin >> input.first >> input.second;
		v.push_back(input);
	}

	stable_sort(v.begin(), v.end());

	for(int i = 0; i < n; ++i)
	{
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}