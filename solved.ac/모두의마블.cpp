/*
	실버3
	백준 12845번 모두의 마블
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count;
	vector<int> arr;
	int maxInput = 0;
	cin >> count;

	for(int i = 0; i < count; ++i)
	{
		int input;
		cin >> input;

		if(maxInput != max(maxInput, input))
		{
			if(maxInput != 0)
				arr.push_back(maxInput);

			maxInput = input;
		}
		else
			arr.push_back(input);
	}

	int answer = maxInput * ((count - 1) > 0 ? count - 1: 1);
	for(int i : arr)
	{
		answer += i;
	}

	cout << answer << endl;

	return 0;
}