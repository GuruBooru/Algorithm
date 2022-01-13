/*
	���5
	���� 2631�� �ټ����
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> input(n);
	vector<int> lis(n);
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	// ������ ���� input�� lis�� ���� ū lis + 1�� �� lis
	lis[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		int max_lis = 0;
		for (int j = 0; j < i; ++j)
		{
			if (input[i] < input[j])
				continue;

			max_lis = max(lis[j], max_lis);
		}
		lis[i] = max_lis + 1;
	}

	int max_lis = 0;
	for (int l : lis)
	{
		max_lis = max(max_lis, l);
	}
	cout << n - max_lis;

	return 0;
}