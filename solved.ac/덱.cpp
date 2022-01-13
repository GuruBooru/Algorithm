/*
	실버4
	백준 10866번 덱
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	int n;
	deque<int> deque;
	scanf("%d\n", &n);

	for(int i = 0; i < n; ++i)
	{
		string cmd;
		int value;
		getline(cin, cmd);

		//push_front, push_back -> value와 분류	
		if(cmd.find(" ") != string::npos)
		{
			int pos = cmd.find(" ");
			value = stoi(cmd.substr(pos));
			cmd = cmd.substr(0, pos);
		}

		if(cmd.find("push") != string::npos)
		{
			if(cmd.find("front") != string::npos)
				deque.push_front(value);
			else if (cmd.find("back") != string::npos)
				deque.push_back(value);
		}
		else
		{
			if (cmd.find("pop") != string::npos)
			{
				if (cmd.find("front") != string::npos)
				{
					if (deque.empty())
						value = -1;
					else
					{
						value = deque.front();
						deque.pop_front();
					}
				}
				else if (cmd.find("back") != string::npos)
				{
					if(deque.empty())
						value = -1;
					else
					{
						value = deque.back();
						deque.pop_back();
					}
				}
			}
			else if (!cmd.compare("size"))
			{
				value = deque.size();
			}
			else if (!cmd.compare("empty"))
			{
				value = deque.empty() ? 1 : 0;
			}
			else if (!cmd.compare("front"))
			{
				value = deque.empty() ? -1 : deque.front();
			}
			else if (!cmd.compare("back"))
			{
				value = deque.empty() ? -1 : deque.back();
			}

			cout << value << endl;
		}
	}

	return 0;
}