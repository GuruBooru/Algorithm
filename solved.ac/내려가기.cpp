/*
	골드4
	백준 2096번 내려가기
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int total[2][3] = { {0, 0, 0}, {0, 0, 0} };
	for(int i = 0; i < n; ++i)
	{
		int input[3];
		cin >> input[0] >> input[1] >> input[2];

		int left_min = min(total[0][0], total[0][1]);
		int right_min = min(total[0][1], total[0][2]);
		int left_max = max(total[1][0], total[1][1]);
		int right_max = max(total[1][1], total[1][2]);

		total[0][0] = input[0] + left_min;
		total[0][1] = input[1] + min(left_min, right_min);
		total[0][2] = input[2] + right_min;

		total[1][0] = input[0] + left_max;
		total[1][1] = input[1] + max(left_max, right_max);
		total[1][2] = input[2] + right_max;
	}

	int min_value = min(total[0][0], min(total[0][1], total[0][2]));
	int max_value = max(total[1][0], max(total[1][1], total[1][2]));

	cout << max_value << " " << min_value;

	return 0;
}