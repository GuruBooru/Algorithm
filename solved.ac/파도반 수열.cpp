/*
	�ǹ�3
	���� 9461�� �ĵ��� ����
*/

#include <iostream>

using namespace std;

long long arr[101] = {0, 1, 1, 1, 2, 2, 3, };

int main()
{
	for(int i = 7; i <= 100; ++i)
	{
		arr[i] = arr[i-1] + arr[i - 5];
	}

	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}

	return 0;
}