/*
	�����1
	���� 2869�� �����̴� �ö󰡰� �ʹ�
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