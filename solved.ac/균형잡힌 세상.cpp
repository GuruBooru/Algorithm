/*
	�ǹ�4
	���� 4949�� �������� ����
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;

	while(true)
	{
		getline(cin, str);
		if(str == ".")
			break;

		stack<char> s;
		bool flag = true;
		for(char c : str)
		{
			if(c == '(' || c == '[')
				s.push(c);
			else if(!s.empty() && ((c == ')' && s.top() == '(') || (c == ']' && s.top() == '[')))
				s.pop();
			else if(c == ')' || c == ']')
			{
				flag = false;
				break;
			}
		}
		if(!s.empty())
			flag = false;
	

		if(flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}