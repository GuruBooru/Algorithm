///*
//	골드3 - 미완
//	백준 16135번 OBB(Oriented bounding box)
//	출처 - 서울 과학고 SciOI 2018 1번
//*/
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<pair<double, double>> rec1;
//vector<pair<double, double>> rec2;
//
//int main()
//{
//	pair<double, double> center1, center2;
//	for (int i = 0; i < 4; ++i)
//	{
//		int inputX;
//		int inputY;
//		cin >> inputX >> inputY;
//		rec1.push_back({inputX, inputY});
//		center1.first += inputX;
//		center1.second += inputY;
//	}
//	center1.first /= 4;
//	center1.second /= 4;
//	for (int i = 0; i < 4; ++i)
//	{
//		int inputX;
//		int inputY;
//		cin >> inputX >> inputY;
//		rec2.push_back({ inputX, inputY });
//		center2.first += inputX;
//		center2.second += inputY;
//	}
//	center2.first /= 4;
//	center2.second /= 4;
//
//	pair<double, double> d = {center1.first - center2.first, center1.second - center2.second};
//	double dSize = pow(d.first, 2) + pow(d.second, 2);
//	pair<double, double> unitD = {sqrt((pow(d.first, 2) / dSize)), sqrt((pow(d.second, 2) / dSize))};
//
//	// 두 직사각형이 겹치지 않음을 구하시오
//	bool checkFlag = true;
//
//	// 사각형의 중심좌표 간 벡터 >= 중심좌표-각 변의 중점까지의 벡터와 단위 벡터의 내적의 합것
//	for(int i = 0; i < 4; ++i)
//	{
//		pair<double, double> centerP = {(rec1[i].first + rec1[(i + 1) % 4].first) / 2, (rec1[i].second + rec1[(i + 1) % 4].second) / 2};
//		pair<double, double> curV = {centerP.first - d.first, centerP.second - d.second};
//		curV = {curV.first * unitD.first, curV.second * unitD.second};
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		pair<double, double> centerP = { (rec2[i].first + rec2[(i + 1) % 4].first) / 2, (rec2[i].second + rec2[(i + 1) % 4].second) / 2 };
//		pair<double, double> curV = { centerP.first - d.first, centerP.second - d.second };
//		curV = { curV.first * unitD.first, curV.second * unitD.second };
//	}
//	// 단위 벡터 = 중심좌표 간 벡터의 단위벡터
//	// 중심좌표-변의 중점까지의 벡터의 크기 중 2개는 0이상의 양수, 2개는 0이하의 음수로 나타남
//	// 해당 벡터 중 양수인 부분과 음수인 부분을 합하여 연산
//
//
//
//	if(checkFlag)
//		printf("1\n");
//	else
//		printf("0\n");
//
//	return 0;
//}