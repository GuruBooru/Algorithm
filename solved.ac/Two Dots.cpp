///*
//	골드4
//	백준 16929번 Two Dots
//*/
//
//#include <iostream>
//
//using namespace std;
//
//char map[50][50];
//bool visited[50][50];
//char start_char;
//
//void dfs(int row, int col)
//{
//	
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int row = 0; row < n; ++row)
//	{
//		for (int col = 0; col < m; ++col)
//		{
//			cin >> map[row][col];
//		}
//	}
//
//	for (int row = 0; row < n; ++row)
//	{
//		for (int col = 0; col < m; ++col)
//		{
//			if (visited[row][col])
//				continue;
//
//			start_char = map[row][col];
//			dfs(row, col);
//		}
//	}
//
//	return 0;
//}