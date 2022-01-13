/*
	실버3
	백준 2630번 색종이 만들기
*/

#include <iostream>

using namespace std;

int arr[128][128];

pair<int, int> solution(int startX, int endX, int startY, int endY)
{
	pair<int, int> ret = {0, 0};

	int color = arr[startY][startX];
	bool check = true;
	for(int i = startY; i < endY; ++i)
	{
		for(int j = startX; j < endX; ++j)
		{
			if(color != arr[i][j])
			{
				pair<int, int> r1 = solution(startX, (startX + endX) / 2, startY, (startY + endY) / 2);
				pair<int, int> r2 = solution((startX + endX) / 2, endX, startY, (startY + endY) / 2 );
				pair<int, int> r3 = solution(startX, (startX + endX) / 2, (startY + endY) / 2, endY);
				pair<int, int> r4 = solution((startX + endX) / 2, endX, (startY + endY)/2, endY);

				ret.first += r1.first + r2.first + r3.first + r4.first;
				ret.second += r1.second + r2.second + r3.second + r4.second;
				check = false;
				break;
			}
		}
		if (check == false)
			break;
	}
	if(check)
		color == 0 ? ret.first = 1 : ret.second = 1;

	return ret;
}

int main()
{
	int n;
	cin >> n;
	
	int blue = 0;
	int white = 0;
	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			cin >> arr[row][col];
		}
	}
	
	pair<int, int> answer = solution(0, n, 0, n);
	cout << answer.first << "\n"
		<< answer.second << "\n";

	return 0;
}