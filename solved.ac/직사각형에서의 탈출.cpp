/*
	브론즈3
	백준 1085번 직사각형에서의 탈출
*/

#include <iostream>

using namespace std;

int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	// x, y, w-x, h-y
	int output = min(x, y);
	output = min(output, w-x);
	output = min(output, h-y);

	cout << output << endl;

	return 0;
}