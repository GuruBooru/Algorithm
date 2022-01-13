///*
//	½Ç¹ö2
//	¹éÁØ 18113¹ø ±×¸£´Ù ±è°¡³ð
//*/
//
//#include <iostream>
//#include <vector>
//#include <limits.h>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, k, m;	// n : ±è¹ä °³¼ö, k : ²¿´Ù¸® ±æÀÌ, m : ±è¹ä Á¶°¢ ÃÖ¼Ò °³¼ö
//	cin >> n >> k >> m;
//
//	vector<int> list;
//	int p = -1;
//	int max_p = 0;
//	int min_p = 1;
//	for (int i = 0; i < n; ++i)
//	{
//		int input;
//		cin >> input;
//		
//		if (input >= 2 * k)
//			input -= 2 * k;
//		else
//			input -= k;
//
//		if (input <= 0)
//			continue;
//
//		max_p = max(max_p, input);
//		p = max_p;
//		list.push_back(input);
//	}
//
//	int count = 0;
//	while (min_p <= max_p)
//	{
//		count = 0;
//		for (int i : list)
//		{
//			count += i / p;
//		}
//
//		if (count < m)
//		{
//			max_p = p - 1;
//			p = (max_p + min_p) / 2;
//		}
//		else
//		{
//			min_p = p + 1;
//			p = (max_p + min_p) / 2;
//		}
//	}
//	if (count < m)
//		p = -1;
//	cout << p;
//
//	return 0;
//}