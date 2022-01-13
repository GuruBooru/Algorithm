/*
	실버2
	백준 1780번 종이의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

struct answer
{
	int one = 0;
	int zero = 0;
	int neg = 0;
};

vector<vector<int>> v;

answer solution(int startX, int endX, int startY, int endY)
{
	answer ans;
	int type = v[startY][startX];
	bool check = true;

	int iX = (endX - startX) / 3;
	int iY = (endY - startY) / 3;

	for(int row = startY; row < endY; ++row)
	{
		for(int col = startX; col < endX; ++col)
		{
			if(type != v[row][col])
			{
				answer r[9];
				r[0] = solution(startX, startX + iX, startY, startY + iY);
				r[1] = solution(startX + iX, startX + 2 * iX, startY, startY + iY);
				r[2] = solution(startX + 2 * iX, endX, startY, startY + iY);

				r[3] = solution(startX, startX + iX, startY + iY, startY + 2 * iY);
				r[4] = solution(startX + iX, startX + 2 * iX, startY + iY, startY + 2 * iY);
				r[5] = solution(startX + 2 * iX, endX, startY + iY, startY + 2 * iY);

				r[6] = solution(startX, startX + iX, startY + 2 * iY, endY);
				r[7] = solution(startX + iX, startX + 2 * iX, startY + 2 * iY, endY);
				r[8] = solution(startX + 2 * iX, endX, startY + 2 * iY, endY);

				for(int i = 0; i < 9; ++i)
				{
					ans.neg += r[i].neg;
					ans.one += r[i].one;
					ans.zero += r[i].zero;
				}

				check = false;
				break;
			}
		}
		if(check == false)
			break;
	}
	if(check)
	{
		switch(type)
		{
		case -1:
			ans.neg = 1;
			break;
		case 0:
			ans.zero = 1;
			break;
		case 1:
			ans.one = 1;
			break;
		}
		
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;

	v = vector<vector<int>>(n);
	for(int row = 0; row < n; ++row)
	{
		v[row] = vector<int>(n);
		for(int col = 0; col < n; ++col)
			cin >> v[row][col];
	}

	answer ans = solution(0, n, 0, n);
	cout << ans.neg << "\n"
		<< ans.zero << "\n"
		<< ans.one << "\n";

	return 0;
}