///*
//	실버1
//	백준 16564번 히오스 프로게이머
//*/
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, k;
//	cin >> n >> k;
//	vector<long long> levels;
//	long long min_level = 1;
//	long long max_level = 2'000'000'000;
//
//	for (int i = 0; i < n; ++i)
//	{
//		long long level;
//		cin >> level;
//
//		levels.push_back(level);
//	}
//
//	long long answer;
//	while (min_level <= max_level)
//	{
//		long long p_level = (min_level + max_level) / 2;
//		long long sum = 0;
//		for (int level : levels)
//		{
//			sum += max(p_level - level, (long long)0);
//		}
//
//		if (sum > k)
//			max_level = p_level - 1;
//		else
//		{
//			answer = p_level;
//			min_level = p_level + 1;
//		}
//		
//	}
//	cout << answer;
//
//	return 0;
//}