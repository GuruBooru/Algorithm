/*
	�ǹ�5
	���� 2609�� �ִ������� �ּҰ����
*/

#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	if(n < m)
		swap(n, m);

	int nInput = n;
	int mInput = m;

	while(mInput != 0)
	{
		nInput = nInput % mInput;
		swap(nInput, mInput);
	}
	int gcd = nInput;
	int lcm = n * m / gcd;

	cout << gcd << endl << lcm << endl;
	return 0;
}