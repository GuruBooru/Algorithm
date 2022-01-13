///*
//	골드4 - 미완
//	백준 1647번 도시 분할 계획
//*/
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<pair<int, pair<int, int>>> input;
//map<int, int> check;
//
//int main()
//{
//	int n, m;
//	int answer = 0;
//	cin >> n >> m;
//
//	for(int i = 0; i < m; ++i)
//	{
//		int a, b, v;
//		cin >> a >> b >> v;
//		input.push_back({v, {a, b}});
//		check[a] = a;
//		check[b] = b;
//	}
//	sort(input.begin(), input.end());
//
//	int count = 1;
//	int dCount = 0;
//	for(pair<int, pair<int, int>> i : input)
//	{
//		if(dCount == n-2)
//			break;
//		pair<int, int> curP = i.second;
//
//
//		/*if(check[curP.first] == check[curP.second] && (check[curP.first] & check[curP.second]))
//		{
//			continue;
//		}
//		else
//		{
//			if(check[curP.first] == 0 && check[curP.second] == 0)
//			{
//				check[curP.first] = count;
//				check[curP.second] = count;
//				++count;
//			}
//			else if(check[curP.first] == 0 || check[curP.second] == 0)
//			{
//				int curCount = check[curP.first] ? check[curP.first] : check[curP.second];
//				check[curP.first] = curCount;
//				check[curP.second] = curCount;
//			}
//			else
//			{
//				int curCount = check[curP.first] < check[curP.second] ? check[curP.first] : check[curP.second];
//				int compareCount = check[curP.first] > check[curP.second] ? check[curP.first] : check[curP.second];
//
//				for(pair<int, int> p : check)
//				{
//					if(p.second == compareCount)
//						check[p.first] = curCount;
//				}
//			}
//			answer += i.first;
//		}*/
//		dCount++;
//	}
//	cout << answer << endl;
//
//	return 0;
//}