/*
	�ǹ�2
	���� 14620�� �ɱ�
	��ó - 2017 ���ϴ� ���α׷��� ������ȸ(IUPC)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input;
vector<vector<bool>> checkArr;

int main()
{
	int size;
	cin >> size;

	for(int i = 0; i < size; ++i)
	{
		input.push_back({});
		checkArr.push_back({});
		for(int j = 0; j < size; ++j)
		{
			int inputValue;
			cin >> inputValue;

			input[i].push_back(inputValue);
			checkArr[i].push_back(true);
		}
	}

	int arr[3] = {200, 200, 200};
	for(int i = 1; i < size-1; ++i)
	{
		for(int j = 1; j < size-1; ++j)
		{
			if(!checkArr[i-1][j] || !checkArr[i][j-1] || !checkArr[i+1][j] || !checkArr[i][j+1])
				continue;

			int value = input[i-1][j] + input[i][j-1] + input[i+1][j] + input[i][j+1] + input[i][j];
			
			bool checkFlag = false;
			for(int k = 0; k < 3; ++k)
			{
				if(arr[k] < value)
					continue;

				if(!checkFlag)
				{
					arr[k] = value;
					checkFlag = true;
				}
			}
		}
	}

	cout << arr[0] + arr[1] + arr[2] << endl;

	return 0;
}