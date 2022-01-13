/*
	실버5
	백준 1181번 단어 정렬
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> arr;
	int num;
	cin >> num;

	for(int i = 0; i < num; ++i)
	{
		string input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end(), [] (string a, string b) {
		if(a.length() == b.length())
			return a < b;

		return a.length() < b.length();
	});

	string preStr = "";
	for(string s : arr)
	{
		if(preStr == s)
			continue;

		cout << s << endl;
		preStr = s;
	}
	return 0;
}