/*
	실버5
	백준 1654번 랜선자르기
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

	// 입력값 중 최댓값을 기준으로 이분 탐색 진행
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