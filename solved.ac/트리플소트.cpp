/*
	�ǹ�4
	���� 20309�� Ʈ���� ��Ʈ
	��ó - �� 2ȸ UNIST �˰��� ���α׷��� ��ô�ȸ Uni-CODE A��
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int size;
	vector<pair<int, int>> arr;
	cin >> size;

	for(int i = 0; i < size; ++i)
	{
		int input;
		cin >> input;
		arr.push_back({input, i});
	}
	sort(arr.begin(), arr.end());

	bool yesOrNo = true;
	for(int i = 0; i < size; ++i)
	{
		if(arr[i].second % 2 != i % 2)
			yesOrNo = false;

	}

	if(yesOrNo)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}