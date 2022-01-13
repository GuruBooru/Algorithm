/*
	½Ç¹ö1
	¹éÁØ 11286¹ø Àý´ñ°ª Èü
*/

#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator() (int a, int b)
	{
		if(abs(a) == abs(b))
			return a > b;

		return abs(a) > abs(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare> q;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if(input != 0)
			q.push(input);
		else
		{
			if(!q.empty())
			{
				input = q.top();
				q.pop();
			}

			cout << input << "\n";
		}
	}

	return 0;
}