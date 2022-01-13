/*
	실버 5
	백준 7568번 덩치
*/

#include <iostream>
#include <vector>
using namespace std;

struct D
{
	int h;
	int w;
	int index;
};
int main()
{
	int n;
	cin >> n;
	
	vector<D> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].h >> v[i].w;
	}

	for(int i = 0; i < n; ++i)
	{
		int count = 1;
		for(int j = 0; j < n; ++j)
		{
			if(i == j)
				continue;

			if(v[i].h < v[j].h && v[i].w < v[j].w)
				++count;
		}
		v[i].index = count;
	}

	for(int i = 0; i < n; ++i)
	{
		if(i != 0)
			cout << " ";
		cout << v[i].index;
	}
	return 0;
}