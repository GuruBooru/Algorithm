/*
	�ǹ�2
	���� 11279�� �ִ� ��

	�ǹ�1
	���� 1927�� �ּ� ��
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// �ִ� ��
	//priority_queue<int, vector<int>, less<int>> q;

	// �ּ���
	priority_queue<int, vector<int>, greater<int>> q;

	for(int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if(input == 0)
		{
			if(!q.empty())
			{
				input = q.top();
				q.pop();
			}
			cout << input << "\n";
		}
		else
			q.push(input);
	}

	return 0;
}