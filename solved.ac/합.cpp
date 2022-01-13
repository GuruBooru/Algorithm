///*
//	��� 3
//	���� 1132�� ��
//*/
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//struct Data
//{
//	long long count;
//	bool zero_flag;
//};
//
//bool compare(const Data& d1, const Data& d2)
//{
//	return d1.count < d2.count;
//}
//
//Data input[10];
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		string s;
//		cin >> s;
//
//		input[s[0]-'A'].zero_flag = true;
//
//		for (int j = 0; j < s.length(); ++j)
//		{
//			input[s[j] - 'A'].count += pow(10, s.length() - (j + 1));
//		}
//	}
//	
//	sort(input, input+10, compare);
//
//	long long answer = 0;
//	bool zero = true;
//	// 0 �� ��� �����ϴ� ���� ã�ƾ� �� �� ����
//	for (int i = 0; i < 10; ++i)
//	{
//		if (zero && !input[i].zero_flag)
//		{
//			zero = false;
//		}
//		else
//			answer += max(i, 1) * input[i].count;
//	}
//
//	cout << answer;
//
//	return 0;
//}