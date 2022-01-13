/*
	실버3
	백준 11659번 구간 합 구하기4
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n + 1);
	arr[0] = 0;
	for(int i = 1; i < n + 1; ++i)
	{
		cin >> arr[i];
		arr[i] += arr[i-1];
	}

	for(int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		cout << arr[end] - arr[start - 1] << "\n";
	}
	return 0;
}