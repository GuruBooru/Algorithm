/*
	실버2
	백준 1541번 잃어버린 괄호
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string e;
	cin >> e;

	int answer = 0;
	bool flag = false;
	
	int cur = 0;
	int mi = e.find('-');
	int pi = e.find('+');

	if (mi == string::npos && pi == string::npos)
		cur = e.length();
	else if (mi == string::npos)
		cur = pi;
	else if (pi == string::npos)
		cur = mi;
	else
		cur = mi < pi ? mi : pi;

	answer = stoi(e.substr(0, cur));
	e.erase(0, cur);

	while(e.length() != 0)
	{
		if(e[0] == '-')
		{
			flag = true;
		}
		e.erase(0, 1);

		mi = e.find('-');
		pi = e.find('+');

		if(mi == string::npos && pi == string::npos)
			cur = e.length();
		else if(mi == string::npos)
			cur = pi;
		else if(pi == string::npos)
			cur = mi;
		else
			cur = mi < pi ? mi : pi;

		if(flag)
		{
			answer -= stoi(e.substr(0, cur));
		}
		else
		{
			answer += stoi(e.substr(0, cur));
		}
		e.erase(0, cur);
	}
	
	cout << answer;

	return 0;
}