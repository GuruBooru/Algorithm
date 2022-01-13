/*
	실버1
	백준 9465번 스티커
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<vector<int>> answer(2);
		answer[0] = vector<int>(n);
		answer[1] = vector<int>(n);

		vector<vector<int>> scores(2);
		scores[0] = vector<int>(n);
		scores[1] = vector<int>(n);

		for (int i = 0; i < n; ++i)
			cin >> scores[0][i];
		for (int i = 0; i < n; ++i)
			cin >> scores[1][i];

		answer[0][0] = scores[0][0];
		answer[1][0] = scores[1][0];

		answer[0][1] = answer[1][0] + scores[0][1];
		answer[1][1] = answer[0][0] + scores[1][1];

		for (int i = 2; i < n; ++i)
		{
			answer[0][i] = scores[0][i] + max(answer[1][i - 1], answer[1][i - 2]);
			answer[1][i] = scores[1][i] + max(answer[0][i - 1], answer[0][i - 2]);
		}

		cout << max(answer[0][n - 1], answer[1][n - 1]) << "\n";
	}
	return 0;
}