///*
//	골드 5
//	백준 9019번 DSLR
//*/
//
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct Data
//{
//	string command;
//	int A;
//};
//string solution(int A, int B)
//{
//	string answer = "";
//	queue<Data> q;
//	q.push({answer, A});
//
//	while(!q.empty() && answer == "")
//	{
//		auto cur_data = q.front();
//		q.pop();
//
//		int A_L = cur_data.A;
//		int A_R = cur_data.A;
//		int a_size = 1000;
//		for (; a_size > 0; a_size /= 10)
//		{
//			if (A / a_size)
//			{
//				A_L = (cur_data.A / a_size) + (cur_data.A % a_size) * 10;
//				A_R = (cur_data.A % 10) * a_size + cur_data.A / 10;
//				break;
//			}
//
//		}
//
//		Data next_commands[4] = {
//									{cur_data.command + 'D', (cur_data.A * 2) % 10000},
//									{cur_data.command + 'S', (cur_data.A - 1 == 0 ? 9999 : cur_data.A - 1)},
//									{cur_data.command + 'L', A_L},
//									{cur_data.command + 'R', A_R}
//								};
//
//		for(Data next_command : next_commands)
//		{
//			if (next_command.A == B)
//			{
//				answer = next_command.command;
//				break;
//			}
//
//			q.push(next_command);
//		}
//	}
//
//	return answer;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	int A, B;
//	string answer;
//
//	cin >> n;
//	for(int i = 0; i < n; ++i)
//	{
//		cin >> A >> B;
//		answer = solution(A, B);
//		cout << answer << "\n";
//	}
//
//	return 0;
//}