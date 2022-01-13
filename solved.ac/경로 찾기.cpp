/*
	실버1
	백준 11403번 경로 찾기
*/

#include <iostream>

using namespace std;

int arr[100][100];

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

	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}

	for(int row = 0; row < n; ++row)
	{
		for(int col = 0; col < n; ++col)
		{
			cout << arr[row][col] << " ";
		}
		cout << "\n";
	}

	return 0;
}