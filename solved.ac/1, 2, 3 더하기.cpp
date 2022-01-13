/*
	실버3
	1, 2, 3 더하기
*/

#include <iostream>
#include <vector>

using namespace std;

int arr[12] = {0, 1, 2, 4};
int main()
{
	int t;
	cin >> t;

	for(int i = 4; i < 12; ++i)
	{
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}

	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		cout << arr[n] << "\n";
	}
	return 0;
}