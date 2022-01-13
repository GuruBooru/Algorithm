/*
	브론즈1
	백준 2869번 달팽이는 올라가고 싶다
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int count = 0;
	int a, b, v;
	cin >> a >>  b >> v;
	
	count = ceil(double(v - a) / (a - b)) + 1; 

	cout << count << endl;

	return 0;
}