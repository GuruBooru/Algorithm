/*
	실버4
	백준 20309번 트리플 소트
	출처 - 제 2회 UNIST 알고리즘 프로그래밍 경시대회 Uni-CODE A번
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