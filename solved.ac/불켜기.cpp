///*
//	골드 3
//	백준 11967번 불켜기
//*/
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//pair<int, int> direct[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//bool rooms[5][5];
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, m;
//	cin >> n >> m;
//
//	//vector<vector<bool>> rooms(n + 1);
//	//for (int i = 0; i <= n; ++i)
//	//	rooms[i] = vector<bool>(n + 1);
//
//	multimap<pair<int, int>, pair<int, int>> switch_list;
//	while (m--)
//	{
//		int x, y, a, b;
//		cin >> x >> y >> a >> b;
//		switch_list.insert({ {x, y}, {a, b} });
//	}
//
//	rooms[1][1] = true;
//	queue<pair<int, int>> q; 
//	pair<multimap<pair<int, int>, pair<int, int>>::iterator, multimap<pair<int, int>, pair<int, int>>::iterator> switches = switch_list.equal_range({1, 1});
//	multimap<pair<int, int>, pair<int, int>>::iterator iter = switches.first;
//	for (; iter != switches.second; ++iter)
//	{
//		q.push(iter->second);
//	}
//
//	while (!q.empty())
//	{
//		pair<int, int> cur_room = q.front();
//		q.pop();
//
//		bool flag = false;
//		for (pair<int, int> d : direct)
//		{
//			pair<int, int> next_room = { cur_room.first + d.first, cur_room.second + d.second };
//			if (!(0 < next_room.first < n + 1) || !(0 < next_room.second < n + 1))
//				continue;
//
//			if (rooms[next_room.first][next_room.second])
//				flag = true;
//		}
//		
//		if (!flag)
//		{
//			q.push(cur_room);
//		}
//
//		if (rooms[cur_room.first][cur_room.second])
//			continue;
//
//		rooms[cur_room.first][cur_room.second] = true;
//		switches = switch_list.equal_range(cur_room);
//		iter = switches.first;
//		for (; iter != switches.second; ++iter)
//		{
//			q.push(iter->second);
//		}
//	}
//
//	return 0;
//}