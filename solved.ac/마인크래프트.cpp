/*
	실버3
	백준 18111번 마인크래프트
*/

#include <iostream>
#include <map>
#include <limits.h>

using namespace std;

int main()
{
	int n, m, b;
	cin >> n >> m >> b;
	
	map<int, int> mapInfo;
	for(int i = 0; i < n * m; ++i)
	{
		int input;
		cin >> input;
		++mapInfo[input];
	}
	
	map<int, int> time;
	for(int i = 0; i < 257; ++i)
	{
		time[i] = 0;
		int useBlock = 0;

		for (pair<int, int> other : mapInfo)
		{
			int differ = (other.first - i) * other.second;

			if (i < other.first)
				time[i] += differ * 2;
			else if (i > other.first)
				time[i] -= differ;

			useBlock += differ;
		}
		if (useBlock + b < 0)
			time[i] = INT_MAX;
	}

	pair<int, int> maxP = {0, INT_MAX};
	for(pair<int, int> p : time)
	{
		if((maxP.second > p.second) || (maxP.second == p.second && maxP.first < p.first))
		{
			maxP = p;
		}
	}
	cout << maxP.second << " " << maxP.first << "\n";
	
	return 0;
}