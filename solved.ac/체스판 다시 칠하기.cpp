/*
	실버5
	백준 1018번 체스판 다시 칠하기
*/

#include <iostream>
#include <limits.h>

using namespace std;

char arr[50][50];
bool blackcheck[50][50];
bool whitecheck[50][50];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> arr[row][col];
			
			if((row + col) % 2 == 0)
			{
				if(arr[row][col] == 'w')
					blackcheck[row][col] = true;

				if (arr[row][col] == 'b')
					whitecheck[row][col] = true;
			}
			else
			{
				if(arr[row][col] == 'b')
					blackcheck[row][col] = true;

				if(arr[row][col] == 'w')
					whitecheck[row][col] = true;
			}
		}
	}

	int output = 64;
	for(int row = 0; row < n - 7; ++row)
	{
		for(int col = 0; col < m - 7; ++col)
		{
			int blackcount = 0;
			int whitecount = 0;
			for(int y = 0; y < 8; ++y)
			{
				for(int x = 0; x < 8; ++x)
				{
					if(blackcheck[row + y][col + x])
						blackcount++;

					if(whitecheck[row + y][col + x])
						whitecount++;
				}
			}

			int count = min(blackcount, whitecount);
			output = min(output, count);
		}
	}

	cout << output << endl;

	return 0;
}