/*
	실버4
	백준 1764번 듣보잡
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> eme(n);
	vector<string> qh(m);
	vector<string> answer;

	for(int i = 0; i < n; ++i)
	{
		cin >> eme[i];
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> qh[i];
	}
	stable_sort(eme.begin(), eme.end());
	stable_sort(qh.begin(), qh.end());

	int emeI = 0;
	int qhI = 0;
	while((emeI != eme.size()) && (qhI != qh.size()))
	{
		if(eme[emeI] == qh[qhI])
		{
			answer.push_back(eme[emeI]);
			emeI++;
			qhI++;
		}
		else if(eme[emeI] < qh[qhI])
			emeI++;
		else if(eme[emeI] > qh[qhI])
			qhI++;
	}

	cout << answer.size() << "\n";
	for(string s : answer)
		cout << s << "\n";

	return 0;
}