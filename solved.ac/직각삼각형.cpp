/*
	브론즈3
	백준 4153번 직각삼각형
*/

#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	while(true)
	{
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0)
			break;

		int diag = max(a, b);
		int side1 = min(a, b);
		int side2 = min(diag, c);
		diag = max(diag, c);

		if(diag * diag == side1 * side1 + side2 * side2)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	
	return 0;
}