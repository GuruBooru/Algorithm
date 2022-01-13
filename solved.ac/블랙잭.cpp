/*
	브론즈2
	백준 2798번 블랙잭
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<int> v;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int answer = 0;
	for(int i = 0; i < n-2; ++i)
	{
		for(int j = i + 1; j < n - 1; ++j)
		{
			for(int k = j + 1; k < n; ++k)
			{
				if(v[i] + v[j] + v[k] > answer && v[i] + v[j] + v[k] <= m)
				{
					answer = v[i] + v[j] + v[k];
				}
			}
		}
	}
	cout << answer << endl;

	return 0;
}