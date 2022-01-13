///*
//	실버3
//	백준 2615번 오목
//	출처 - 한국 정보올림피아드 2003 1번
//*/

#include <iostream>

using namespace std;

struct Answer
{
	int value;
	pair<int, int> index;
};

int board[19][19];
pair<int, int> direct[4] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};

Answer answer;

int main()
{
	for(int row = 0; row < 19; ++row)
	{
		for(int col = 0; col < 19; ++col)
		{
			cin >> board[row][col];
		}
	}

	pair<int, int> curP;
	bool check = false;

	for(int col = 0; col < 19; ++col)
	{
		for(int row = 0; row < 19; ++row)
		{
			curP = {row, col};
			int curValue = board[row][col];
			if(curValue == 0)
				continue;

			for(pair<int, int> d : direct)
			{
				pair<int, int> next[4];
				int nextV[4];

				for(int i = 0; i < 4; ++i)
				{
					if(i == 0)
						next[0] = { curP.first + d.first, curP.second + d.second };
					else
						next[i] = {next[i-1].first + d.first, next[i-1].second + d.second};

					if (next[i].first < 0 || next[i].first > 18 || next[i].second < 0 || next[i].second > 18)
					{
						nextV[i] = 0;
					}
					else
						nextV[i] = board[next[i].first][next[i].second];
				}

				if(curValue != (nextV[0] & nextV[1] & nextV[2] & nextV[3]))
				{
					continue;
				}

				pair<int, int> check[2];
				check[0] = { curP.first - d.first, curP.second - d.second };
				check[1] = { next[3].first + d.first, next[3].second + d.second };

				int checkV[2];
				for(int i = 0; i < 2; ++i)
				{
					if(check[i].first < 0 || check[i].first > 18 || check[i].second < 0 || check[i].second > 18)
					{
						checkV[i] = 0;
					}
					else
					{
						checkV[i] = board[check[i].first][check[i].second];
					}
				}

				if(curValue == checkV[0] || curValue == checkV[1])
					continue;

				answer.value = curValue;
				answer.index = curP;

				printf("%d\n", answer.value);
				if (answer.value)
					printf("%d %d\n", answer.index.first + 1, answer.index.second + 1);

				return 0;
			}
		}
	}

	printf("%d\n", 0);
	return 0;
}