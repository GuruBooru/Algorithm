/*
	실버1
	쿼드 트리
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

char arr[64][64];

void solution(int n, int startR, int startC)
{
	int boundary = n / 2;
	if(boundary == 0)
	{
		cout << arr[startR][startC];
		return;
	}

	int endR = startR + n;
	int endC = startC + n;
	char base = arr[startR][startC];
	bool flag = true;

	for(int row = startR; row < endR; ++row)
	{
		for(int col = startC; col < endC; ++col)
		{
			if(arr[row][col] != base && flag)
			{
				flag = false;
				cout << "(";

				solution(boundary, startR, startC);
				solution(boundary, startR, startC + boundary);
				solution(boundary, startR + boundary, startC);
				solution(boundary, startR + boundary, startC + boundary);

				cout << ")";
				break;
			}
		}
		if(flag != true)
			break;
	}
	if(flag)
		cout << base;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			cin >> arr[row][col];
		}
	}

	solution(n, 0, 0);

	return 0;
}