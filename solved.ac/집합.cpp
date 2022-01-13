/*
	실버5
	백준 11723번 집합
*/

#include <iostream>
#include <string>

using namespace std;

bool flag[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	cin.ignore();

	for(int i = 0; i < m; ++i)
	{
		string cmd;
		int value;
		getline(cin, cmd);
		
		if (cmd.find(" ") != string::npos)
		{
			int pos = cmd.find(" ");
			value = stoi(cmd.substr(pos));
			cmd = cmd.substr(0, pos);
		}

		if(cmd == "add")
		{
			flag[value] = true;
		}
		else if (cmd == "remove")
		{
			flag[value] = false;
		}
		else if(cmd == "check")
		{
			flag[value] ? cout << 1 << "\n" : cout << 0 << "\n";
		}
		else if(cmd == "toggle")
		{
			flag[value] ? flag[value] = false : flag[value] = true;
		}
		else if(cmd == "all")
		{
			for(int i = 0; i < 21; ++i)
				flag[i] = true;
		}
		else if(cmd == "empty")
		{
			for (int i = 0; i < 21; ++i)
				flag[i] = false;
		}
	}
	return 0;
}