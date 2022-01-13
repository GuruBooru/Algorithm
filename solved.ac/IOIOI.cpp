/*
	실버2
	백준 5525번 IOIOI
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	bool flag = false;
	string token = "IOI";
	int length = 0;
	int answer = 0;
	int cur = 0;
	int pos = str.find(token);

	do
	{
		if (pos == cur)
		{
			cur = pos + 2;
			++length;
			if (length >= n)
				++answer;
		}
		else
		{
			cur = pos;
			length = 0;
		}

		pos = str.find(token, cur);
	} while (pos != string::npos);

	cout << answer;

	return 0;
}