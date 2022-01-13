#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		string func;
		int size;
		string num;
		cin >> func >> size >> num;
		deque<int> numArr(size);

		num.erase(0, 1);
		int index = 0;
		string token;
		int tokenSize = 0;
		for(char c : num)
		{
			token[tokenSize] = c;
			if(c == ',' || c == ']' && tokenSize != 0)
			{
				token[tokenSize] = '\0';
				numArr[index++] = stoi(token);
				tokenSize = 0;

				continue;
			}
			++tokenSize;
		}

		bool flag = true;
		for(char c : func)
		{
			if(c == 'R')
				flag = flag ? false : true;
			else if(!numArr.empty())
			{
				if(flag)
					numArr.pop_front();
				else
					numArr.pop_back();
			}
		}

		if(numArr.empty())
			cout << "error\n";
		else
		{
			cout << "[";
			while(!numArr.empty())
			{
				if(flag)
				{
					cout << numArr.front();
					numArr.pop_front();
				}
				else
				{
					cout << numArr.back();
					numArr.pop_back();
				}
				if(!numArr.empty())
					cout << ",";
			}
			cout << "]\n";
		}
	}

	return 0;
}