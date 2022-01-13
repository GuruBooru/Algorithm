/*
	골드 5
	7662번 이중 우선순위 큐
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(; t > 0; --t)
	{
		map<int, int> q;

		int k;
		cin >> k;
		cin.ignore();

		for(; k > 0; --k)
		{
			string command;
			getline(cin, command);
			
			int pos = command.find(" ");
			int value = stoi(command.substr(pos));			
			command = command.substr(0, pos);

			if(command == "I")
			{
				q[value]++;
			}
			if(command == "D" && !q.empty())
			{
				map<int, int>::iterator iter;
				if (value == -1)
				{
					iter = q.begin();
					iter->second--;
				}
				else
				{
					iter = --q.end();
					iter->second--;
				}

				if (iter->second == 0)
					q.erase(iter);
			}
		}

		if(q.empty())
			cout << "EMPTY\n";
		else
		{
			map<int, int>::iterator min_iter = q.begin();
			map<int, int>::iterator max_iter = --q.end();

			cout << max_iter->first << " " << min_iter->first << "\n";
		}
	}
}