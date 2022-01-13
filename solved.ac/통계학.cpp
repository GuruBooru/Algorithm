/*
	실버4
	백준 2108번 통계학
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	int total = 0;
	map<int, int> m;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		total += v[i];
		++m[v[i]];
	}
	sort(v.begin(), v.end());
	
	int frequency = 5000;
	int maxf = 0;
	bool flag = true;
	for(pair<int, int> p : m)
	{
		if(p.second > maxf)
		{
			frequency = p.first;
			maxf = p.second;
			flag = true;
		}
		else if(p.second == maxf && flag)
		{
			frequency = p.first;
			flag = false;
		}
	}

	cout << round((double)total / n) << "\n"
		<< v[n/2] << "\n"
		<< frequency << "\n"
		<< v[n-1] - v[0] << "\n";

	return 0;
}