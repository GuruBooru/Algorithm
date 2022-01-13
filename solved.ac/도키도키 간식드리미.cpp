/*
	실버4
	백준 12789번 도키도키 간식드리미
	출처 - 2016 인하대 프로그래밍 경진대회(IUPC)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int count;
	vector<int> arr;
	cin >> count;
	for(int i = 0; i < count; ++i)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	stack<int> s;
	int index = 1;
	bool flag = true;
	
	for(int i = 0; i < count;)
	{
		if(s.empty() || s.top() > arr[i])
		{
			s.push(arr[i]);
			++i;
		}
		else if (s.top() == index)
		{
			s.pop();
			++index;
		}
		else
		{
			flag = false;
			break;
		}
	}

	if(flag)
		printf("Nice\n");
	else
		printf("Sad\n");
	
	return 0;
}
