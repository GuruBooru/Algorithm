/*
	실버 4
	백준 10773번 제로
*/
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (input)
			s.push(input);
		else
			s.pop();
	}

	int total = 0;
	while (!s.empty())
	{
		total += s.top();
		s.pop();
	}

	cout << total << "\n";
	return 0;
}