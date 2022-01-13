/*
	브론즈 1
	백준 1259번 팰린드롬수
	출처 - 2006 ICPC 뉴질랜드
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	while(true)
	{
		bool flag = true;
		cin >> input;
		if(input == "0")
			break;

		int length = input.length();
		for(int i = 0; i < length / 2; ++i)
		{
			if(input[i] != input[length - i - 1])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}