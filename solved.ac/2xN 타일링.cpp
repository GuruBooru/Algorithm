/*
	�ǹ�3
	���� 11726�� 2*n Ÿ�ϸ�
*/

#include <iostream>

using namespace std;

#define MAXSIZE 10007

long long fibo[1001] = {0, 1,};
long long arr[1001] = {0, 1,};

int main()
{
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		fibo[i] = (fibo[i-2] + fibo[i-1]) % MAXSIZE;
		arr[i] = (arr[i-1] + fibo[i - 1]) % MAXSIZE;
	}

	cout << arr[n];

	return 0;
}