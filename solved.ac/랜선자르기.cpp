/*
	�ǹ�5
	���� 1654�� �����ڸ���
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k, n;
	vector<long long> arr;
	long long minValue = 0;
	long long maxValue = 0;
	long long output = 0;
	int count = 0;

	cin >> k >> n;
	for(int i = 0; i < k; ++i)
	{
		long long input;
		cin >> input;
		
		arr.push_back(input);

		output = max(output, input);
		maxValue = output;
	}

	// �Է°� �� �ִ��� �������� �̺� Ž�� ����
	while(minValue < maxValue)
	{
		count = 0;

		for(int i : arr)
		{
			count += i / output;
		}

		if(count < n)
		{
			maxValue = output - 1;
			output -= (output - minValue) / 2;
		}
		else
		{
			minValue = output + 1;
			output += (maxValue - output) / 2;
		}
	}
	
	printf("%I64d\n", output);
}