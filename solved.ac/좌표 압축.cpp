/*
	실버2
	백준 18870번 좌표 압축
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> index(n);
	vector<int> point(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> index[i];
		point[i] = index[i];
	}
	stable_sort(index.begin(), index.end());
	index.erase(unique(index.begin(), index.end()), index.end());

	for(int i : point)
	{
		cout << lower_bound(index.begin(), index.end(), i) - index.begin() << ' ';
	}

	return 0;
}