/*
	골드5
	백준 1107번 리모컨
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool arr[10];// 0 ~ 9

int solution(int n)
{
	int answer = 0;
	int differ = 600'000;

	queue<pair<int, int>> q;
	for(int i = 0; i < 10; ++i)
	{
		if(arr[i])
			q.push({i, 1});
	}

	pair<int, int> cur;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		if(differ < abs(n - cur.first) + cur.second)
			continue;
		if(cur.second > 6)
			continue;

		differ = abs(n - cur.first) + cur.second;

		for (int i = 0; i < 10; ++i)
		{
				if (arr[i] && cur.first != 0)
					q.push({ cur.first * 10 + i, cur.second + 1 });
		}
	}
	answer = differ;
	if(answer > abs(n - 100))
		answer = abs(n - 100);

	return answer;
}

int main()
{
	int n, m;
	cin >> n >> m;

	memset(arr, 1, sizeof(arr));
	for (int i = 0; i < m; ++i)
	{
		int input;
		cin >> input;
		arr[input] = false;
	}

	/*
		내가 누를 수 있는 숫자 중 가장 해당 채널과 가까운 번호 구하기
	*/
	if (n == 100)
		cout << 0;
	else
	{
		cout << solution(n);
	}


	return 0;
}

/*
반례
5457
3
6 7 8
6

100
5
0 1 2 3 4
0

500000
8
0 2 3 4 6 7 8 9
11117

1555
8
0 1 3 4 5 6 7 9
670

//
98
10
0 1 2 3 4 5 6 7 8 9
2

1
2
1 2
2

//
0
0

1

//
836
9
6 9 1 8 3 4 7 2 5
736

500000
2
1 5
7

6
9
0 2 3 4 5 6 7 8 9
6

11
8
1 3 4 5 6 7 8 9
10

12
9
0 1 3 4 5 6 7 8 9
11

9999
1
9
6

19
8
0 2 3 4 5 6 7 9
3
*/