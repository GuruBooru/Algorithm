/*
	실버4
	백준 11866번 - 요세푸스 문제0
*/
#include <iostream>
#include <queue>

using namespace std;

bool arr[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	queue<int> q;
	queue<int> answer;

	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		q.push(i+1);
	}

	int count = 1;
	while(!q.empty())
	{
		int out = q.front();
		q.pop();

		if(count != k)
		{
			count++;
			q.push(out);
		}
		else
		{
			answer.push(out);
			count = 1;
		}
	}

	cout << '<';
	for(int i = 0; i < n; ++i)
	{
		if(i != 0)
			cout << ", ";
		cout << answer.front();
		answer.pop();
	}
	cout << '>';

	return 0;
}