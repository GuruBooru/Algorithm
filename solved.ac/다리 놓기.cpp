/*
	실버5
	백준 1010번 다리놓기
*/
#include <iostream>

using namespace std;

int main()
{
	int num;
	int westCount, eastCount;

	cin >> num;

	for(int i = 0; i < num; ++i)
	{
		int answer = 1;
		cin >> westCount >> eastCount;

		int rCount = eastCount - westCount;

		rCount = rCount > westCount ? rCount : westCount;

		for(int i = 1; eastCount > rCount; --eastCount)
		{
			answer *= eastCount;
			answer /= i++;
		}

		cout << answer << endl;
	}

	return 0;
}