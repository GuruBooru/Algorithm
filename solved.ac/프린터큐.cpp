/*
	실버3
	백준 1966번 프린터큐
*/

#include <iostream>
#include <queue>

using namespace std;

struct input
{
	int prior;
	int index;
};

int main()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int n, m;
		queue<input> q;
		int maxP = 0;
		int priorCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		cin >> n >> m;

		for(int j = 0; j < n; ++j)
		{
			int p;
			cin >> p;

			q.push({p, j});
			priorCount[p]++;
			if(p > maxP)
				maxP = p;
		}

		int answer = 0;
		while(true)
		{
			input cur = q.front();
			q.pop();

			if(cur.prior < maxP)
				q.push(cur);
			else
			{
				++answer;
				--priorCount[maxP];
				if(cur.index == m)
					break;

				if(priorCount[maxP] == 0)
				{
					for(int i = maxP - 1; i > 0; --i)
					{
						if(priorCount[i])
						{
							maxP = i;
							break;
						}
					}
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}