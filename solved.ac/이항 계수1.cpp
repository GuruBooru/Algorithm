/*
*	�����1
*	���� 11050�� ���װ��1
*/
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int answer = 1;

	// answer = i! / k!	
	for(int i = n; i > k; --i)
	{
		answer *= i;
	}
	// answer = answer / (n-k)!
	for(int i = 1; i <= n - k; ++i)
	{
		answer /= i;
	}

	cout << answer << endl;

	return 0;
}