/*
	골드 5
	백준 14500번 테트로미노
*/

#include <iostream>

using namespace std;

#define MAX_LEVEL 4
struct Direction
{	
	int y;
	int x;
};
Direction direct[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int arr[500][500];
bool check[500][500];
int n, m;
int max_value;

void Solution(int start_y, int start_x, int value, int depth)
{
	if(depth == MAX_LEVEL)
	{
		max_value = max(max_value, value);
		return;
	}
	 
	for(Direction d : direct)
	{
		int next_x = start_x + d.x;
		int next_y = start_y + d.y;

		if(!(0 <= next_y && next_y < n) || !(0 <= next_x && next_x < m))
			continue;

		if(!check[next_y][next_x])
		{
			check[next_y][next_x] = true;
			Solution(next_y, next_x, value + arr[next_y][next_x], depth + 1);
			check[next_y][next_x] = false;
		}
	}
}

// 시작점은 T자 모양 중앙
void FindT(int row, int col)
{
	int value = 0;

	//  O
	// O0O
	if((0 < row && row < n) && (0 < col && col < m - 1))
	{
		value = arr[row][col] + arr[row - 1][col] + arr[row][col - 1] + arr[row][col + 1];
		max_value = max(max_value, value);
	}

	// O0O
	//  O
	if ((0 <= row && row < n - 1) && (0 < col && col < m - 1))
	{
		value = arr[row][col] + arr[row + 1][col] + arr[row][col - 1] + arr[row][col + 1];
		max_value = max(max_value, value);
	}

	// O
	// 0O
	// O
	if ((0 < row && row < n - 1) && (0 <= col && col < m - 1))
	{
		value = arr[row][col] + arr[row - 1][col] + arr[row + 1][col] + arr[row][col + 1];
		max_value = max(max_value, value);
	}

	//  O
	// O0
	//  O
	if ((0 < row && row < n - 1) && (0 < col && col < m))
	{
		value = arr[row][col] + arr[row - 1][col] + arr[row + 1][col] + arr[row][col - 1];
		max_value = max(max_value, value);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> arr[row][col];
		}
	}

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < m; ++col)
		{
			check[row][col] = true;
			Solution(row, col, arr[row][col], 1);
			check[row][col] = false;
			
			FindT(row, col);
		}
	}
	cout << max_value << "\n";

	return 0;
}