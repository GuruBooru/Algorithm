/*
	골드3
	백준 1943번 동전 분배
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Input
{
	int value;
	int count;
};

int solution()
{
	int n;
	cin >> n;

	vector<Input> list(n);
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> list[i].value >> list[i].count;
		
		total += list[i].value * list[i].count;
	}

	if (total % 2)
		return 0;

	total /= 2;
	vector<bool> check(total + 1);
	check[0] = true;
	for (Input input : list)
	{
		for (int i = total; i >= 0; --i)
		{
			if (i + input.value > total)
				continue;

			if (check[i] == false)
				continue;

			for (int c = 1; c <= input.count; ++c)
			{
				int v = input.value * c;
				
				if (i + v > total)
					break;

				check[i + v] = true;
			}
		}
	}

	return check[total] ? 1 : 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << solution() << endl;
	}

	return 0;
}