/*
	실버3
	백준 11399번 ATM
*/

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int answer = 0;
	int time = 0;
	for(int i = 0; i < n; ++i)
	{
		time += arr[i];
		answer += time;
	}
	cout << answer;
	return 0;
}