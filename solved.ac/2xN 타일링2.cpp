/*
	�ǹ�3
	���� 11727�� 2*N Ÿ�ϸ�2
*/

#include <iostream>

using namespace std;

#define MAXSIZE 10007

int arr[1001] = {0, 1, 3, };

int main()
{
	int n;
	cin >> n;
	for(int i = 3; i <= n; ++i)
	{
		arr[i] = (arr[i-1] + arr[i-2] * 2) % MAXSIZE;
	}
	cout << arr[n];

	return 0;
}