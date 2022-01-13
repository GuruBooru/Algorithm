/*
	실버4
	백준 10816번 - 숫자 카드 2
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	map<int, int> card;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		++card[input];
	}

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int output;
		cin >> output;

		if(i)
			cout << " ";

		if(card.find(output) != card.end())
			cout << card[output];
		else
			cout << 0;
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		cout<<upper_bound(arr.begin(),arr.end(),a)-lower_bound(arr.begin(),arr.end(),a)<<" ";

	}
	return 0;
}

*/