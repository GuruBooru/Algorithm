/*
	골드 5
	백준 10026번 적록색약
*/

#include <iostream>
#include <vector>
#include <string>

struct Direction
{
	int row;
	int col;
};
Direction direct[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int n;
std::vector<std::string> arr;
std::vector<std::vector<int>> check;
int area_count, color_weakness_count;


void input()
{
	std::cin >> n;
	arr = std::vector<std::string>(n);
	check = std::vector<std::vector<int>>(n);
	for(int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		check[i] = std::vector<int>(n);
	}
}

void FindArea(int cur_row, int cur_col)
{
	check[cur_row][cur_col] = 1;

	for(Direction d: direct)
	{
		int next_row = cur_row + d.row;
		int next_col = cur_col + d.col;

		if(!(0 <= next_row && next_row < n) || !(0 <= next_col && next_col < n))
			continue;

		if(arr[next_row][next_col] != arr[cur_row][cur_col])
			continue;
		
		if(check[next_row][next_col] == 1)
			continue;

		FindArea(next_row, next_col);
	}
}

void FindColorWeaknessArea(int cur_row, int cur_col)
{
	check[cur_row][cur_col] = 2;

	for (Direction d : direct)
	{
		int next_row = cur_row + d.row;
		int next_col = cur_col + d.col;

		if (!(0 <= next_row && next_row < n) || !(0 <= next_col && next_col < n))
			continue;

		if (arr[next_row][next_col] != arr[cur_row][cur_col])
		{
			if(arr[next_row][next_col] == 'B' || arr[cur_row][cur_col] == 'B')
				continue;
		}
			
		if (check[next_row][next_col] == 2)
			continue;

		FindColorWeaknessArea(next_row, next_col);
	}
}

void solution()
{
	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			if(check[row][col] == 1)
				continue;

			FindArea(row, col);
			++area_count;
		}
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			if (check[row][col] == 2)
				continue;

			FindColorWeaknessArea(row, col);
			++color_weakness_count;
		}
	}
	
	std::cout << area_count << " " << color_weakness_count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();

	return 0;
}