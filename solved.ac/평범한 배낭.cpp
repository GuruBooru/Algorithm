/*
	골드 5
	백준 12865번 평범한 배낭
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Input
{
	int w;
	int v;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<Input> list(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> list[i].w >> list[i].v;
	}

	vector<int> values(k + 1);
	for (int i = 0; i < n; ++i)
	{
		for (int w = k; w > 0; --w)
		{
			if (w - list[i].w < 0)
				break;

			values[w] = max(values[w], list[i].v + values[w - list[i].w]);
		}
	}

	int answer = 0;
	for (int value : values)
	{
		answer = max(value, answer);
	}

	cout << answer;

	return 0;
}