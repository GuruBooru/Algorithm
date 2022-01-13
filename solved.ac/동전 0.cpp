/*
	실버2
	백준 11047번 동전0
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for(int i = 1; i <= n; ++i)
	{
		cin >> v[n - i];
	}

	int answer = 0;
	for(int i : v)
	{
		int tmp = k / i;
		k %= i;

		answer += tmp;
	}
	
	cout << answer;
	return 0;
}