/*
	실버4
	백준 9012번 괄호
*/
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	string input;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> input;

		stack<char> s;
		for(char c : input)
		{
			if(c == '(')
				s.push(c);
			else
			{
				if(!s.empty() && s.top() == '(')
					s.pop();
				else
					s.push(c);
			}
		}
		if(s.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}