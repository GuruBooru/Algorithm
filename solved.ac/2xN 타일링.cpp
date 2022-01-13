/*
	실버3
	백준 11726번 2*n 타일링
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