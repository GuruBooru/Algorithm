/*
	�ǹ�4
	���� 17219�� ��й�ȣ ã��
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	map<string, string> answer;
	for(int i = 0; i < n; ++i)
	{
		string address, pw;
		cin >> address >> pw;
		answer[address] = pw;
	}
	for(int i = 0; i < m; ++i)
	{
		string address;
		cin >> address;
		cout << answer[address] << "\n";
	}

	return 0;
}