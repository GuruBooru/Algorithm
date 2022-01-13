/*
	�ǹ�5
	���� 2751�� �� �����ϱ�2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 2'000'001
#define ZEROPOINT 1'000'000

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	bool* arr = new bool[MAXSIZE];

	for(int i = 0; i < n; ++i)
	{
		int input;
		scanf("%d", &input);

		arr[ZEROPOINT + input] = true;
	}

	for(int i = 0; i < MAXSIZE; ++i)
	{
		if(arr[i])
			printf("%d\n", i - ZEROPOINT);
	}
	
	delete[] arr;
	return 0;
}