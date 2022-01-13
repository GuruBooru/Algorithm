/*
	�ǹ�4
	���� 12789�� ��Ű��Ű ���ĵ帮��
	��ó - 2016 ���ϴ� ���α׷��� ������ȸ(IUPC)
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
