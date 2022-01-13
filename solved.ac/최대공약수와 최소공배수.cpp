/*
	실버5
	백준 2609번 최대공약수와 최소공배수
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