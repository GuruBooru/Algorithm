///*
//	°ñµå 3
//	¹éÁØ 2024¹ø ¼±ºÐ µ¤±â
//*/
//
//#include <iostream>
//#include <map>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	map<int, int> list;
//
//	int m;
//	cin >> m;
//
//	while (true)
//	{
//		int l, r;
//
//		cin >> l >> r;
//
//		if (l == 0 && r == 0)
//			break;
//		if (r <= 0)
//			continue;
//
//		list[l] = max(r, list[l]);
//	}
//
//	stack<pair<int, int>> s;
//	int preR = 0;
//	for (pair<int, int> p : list)
//	{
//		if (s.empty() && p.first <= 0)
//		{
//			s.push(p);
//			continue;
//		}
//
//		pair<int, int> top = s.top();
//		if (top.second >= m)
//			break;
//
//		if (top.second < p.first)
//			break;
//
//		if (preR >= p.first && top.second < p.second)
//		{
//			s.pop();
//			if (s.empty())
//				preR = 0;
//
//			s.push(p);
//		}
//		else
//		{
//			s.push(p);
//			preR = top.second;
//		}
//	}
//
//	int answer = 0;
//	if (!s.empty() && s.top().second >= m)
//		answer = s.size();
//
//	cout << answer;
//
//	return 0;
//}