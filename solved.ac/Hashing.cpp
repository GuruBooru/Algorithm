/*
	브론즈2
	백준 15829번 Hashing
*/

#include <iostream>
#include <string>

using namespace std;

#define R 31
#define M 1234567891

int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	
	long long answer = 0;
	long long curR = 1;
	for(int i = 0; i < l; ++i)
	{
		answer += ((long long)s[i] - 'a' + 1) * curR;
		curR *= 31;
		curR %= M;
	}
	answer %= M;

	cout << answer;
	return 0;
}