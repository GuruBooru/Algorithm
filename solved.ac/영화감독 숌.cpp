/*
	실버 5
	백준 1436번 영화감독 숌
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nextSixCount = 6;
	int n;
	cin >> n;

	int num = 666;
	while(true)
	{
		string numStr = to_string(num);
		if(numStr.find("666") != string::npos)
		{
			--n;
			
			if(n == 0)
				break;
		}
		num++;
	}
	cout << num << endl;

	return 0;
}