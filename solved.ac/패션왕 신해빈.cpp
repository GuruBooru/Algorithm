/*
	실버3
	백준 9375번 패션왕 신해빈
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		map<string, int> m;
		for(int j = 0; j < n; ++j)
		{
			string name, type;
			cin >> name >> type;
			++m[type];
		}

		int output = 0;
		for(pair<string, int> p : m)
		{
			output = output == 0 ? p.second + 1 : output * (p.second + 1);
		}
		if(output != m.size())
			output -= 1;
		cout << output << "\n";
	}
	return 0;
}