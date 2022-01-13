/*
	실버3
	백준 1874번 - 스택 수열
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int> s;
	vector<char> output;
	bool flag = true;
	int n;
	cin >> n;

	int num = 1;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (s.empty() || s.top() < input)
		{
			do
			{
				s.push(num++);
				output.push_back('+');
			} while (s.top() != input);
		}

		if (s.top() == input)
		{
			s.pop();
			output.push_back('-');
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
		for (char c : output)
		{
			cout << c << "\n";
		}
	else
		cout << "NO\n";

	return 0;
}