/*
	실버4
	백준 10845번 - 큐
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int n;
	queue<int> s;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
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

		if (cmd == "push")
		{
			s.push(value);
		}
		else
		{
			if (cmd == "pop")
			{
				if (s.empty())
					value = -1;
				else
				{
					value = s.front();
					s.pop();
				}
			}
			else if (cmd == "size")
			{
				value = s.size();
			}
			else if (cmd == "empty")
			{
				value = s.empty() ? 1 : 0;
			}
			else if (cmd == "front")
			{
				if (s.empty())
					value = -1;
				else
					value = s.front();
			}
			else if(cmd == "back")
			{
				if(s.empty())
					value = -1;
				else
					value = s.back();
			}

			printf("%d\n", value);
		}
	}

	return 0;
}