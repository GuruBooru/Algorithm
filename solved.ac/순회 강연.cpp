///*
//	골드 3
//	백준 2109번 순회강연
//*/
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//struct Data
//{
//	int d;
//	int p;
//};
//
//bool compare(const Data& d1, const Data& d2)
//{
//	if (d1.d == d2.d)
//		return d1.p > d2.p;
//
//	return d1.d > d2.d;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<Data> list(n);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> list[i].p >> list[i].d;
//	}
//
//	stable_sort(list.begin(), list.end(), compare);
//
//	int cur_day = 10001;
//	int answer = 0;
//	// 여기 우선순위 큐 쓰는게 나을 듯
//	for (Data d : list)
//	{
//		if (cur_day > d.d)
//		{
//			answer += d.p;
//			cur_day = d.d - 1;
//		}
//		else if (cur_day == d.d)
//		{
//			answer += d.p;
//			cur_day--;
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}