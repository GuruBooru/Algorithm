/*
	실버4
	백준 2164번 카드2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<int> q;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		q.push(i + 1);
	}

	bool flag = false;
	while(q.size() != 1)
	{
		int tmp = q.front();
		q.pop();

		if(flag)
		{
			q.push(tmp);
			flag = false;
		}
		else
		{
			flag = true;
		}
	}
	int answer = q.front();
	printf("%d", answer);
	return 0;
}