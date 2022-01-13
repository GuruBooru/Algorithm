/*
	실버4
	백준 1620번 나는야 포켓몬 마스터 이다솜
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> d;
	vector<string> v(n + 1);
	for(int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		d[name] = i + 1;
		v[i + 1] = name;
	}
	for(int i = 0; i < m; ++i)
	{
		string input;
		cin >> input;

		if(input[0] < 'A' || input[0] > 'Z')
		{
			cout << v[stoi(input)];
		}
		else
		{
			cout << d[input];
		}
		cout << "\n";
	}

	return 0;
}