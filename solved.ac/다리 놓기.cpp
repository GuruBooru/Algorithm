/*
	�ǹ�5
	���� 1010�� �ٸ�����
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