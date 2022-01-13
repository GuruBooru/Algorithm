/*
	실버1
	백준 1074번 Z
*/

#include <iostream>
#include <math.h>

using namespace std;

int solution(int startR, int startC, int n, int r, int c)
{
	int result = 0;
	
	if(n == -1)
		return result;

	int range = pow(2, n);
	int endR = startR + range;
	int endC = startC + range;
	int boundaryR = startR + range / 2;
	int boundaryC = startC + range / 2;
	
	if(r < boundaryR)
	{ 
		if(c < boundaryC)
		{
			result += solution(startR, startC, n-1, r, c);
		}
		else
		{
			result += pow(range, 2) / 4;
			result += solution(startR, boundaryC, n-1, r, c);
		}
	}
	else
	{
		result += pow(range, 2) / 2;

		if (c < boundaryC)
		{
			result += solution(boundaryR, startC, n - 1, r, c);
		}
		else
		{
			result += pow(range, 2) / 4;
			result += solution(boundaryR, boundaryC, n - 1, r, c);
		}
	}

	return result;
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;

	cout << solution(0, 0, n, r, c);

	return 0;
}