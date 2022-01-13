/*
	�ǹ� 1
	���� 6064�� ī�� �޷�
	������ ����
	��Ŭ���� ȣ������ ����Ͽ� ������ �� ����
*/

#include <iostream>

using namespace std;

int main()
{
	int k;
	cin >> k;

	for(int i = 0; i < k; ++i)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int answer = 0;
		int maxYear = m * n;
		int a = 0;
		int b = 0;

		while ((m * a + x <= maxYear) && (n * b + y <= maxYear))
		{
			if (m * a + x < n * b + y)
				++a;
			else if (m * a + x > n * b + y)
				++b;
			else
			{
				answer = m * a + x;
				break;
			}
		}
		if(answer == 0)
			answer = -1;

		cout << answer << "\n";
	}

	return 0;
}