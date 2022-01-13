/*
	실버5
	백준 17626번 Four Squares
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arrCount[500001] = {0, 1, };
int arr[230];

int main()
{
	for(int i = 0; i < 230; ++i)
		arr[i] = i * i;

	int n;
	cin >> n;

	
	for (int i = 2; i <= n; ++i)
	{
		int minCount = 4;
		for(int j = 1; arr[j] <= i; ++j)
		{
			minCount = min(minCount, arrCount[i - arr[j]]);
		}
		arrCount[i] = minCount + 1;
	}

	cout << arrCount[n] << "\n";
	return 0;
}