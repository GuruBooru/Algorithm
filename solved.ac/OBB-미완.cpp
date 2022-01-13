///*
//	���3 - �̿�
//	���� 16135�� OBB(Oriented bounding box)
//	��ó - ���� ���а� SciOI 2018 1��
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
//	// �� ���簢���� ��ġ�� ������ ���Ͻÿ�
//	bool checkFlag = true;
//
//	// �簢���� �߽���ǥ �� ���� >= �߽���ǥ-�� ���� ���������� ���Ϳ� ���� ������ ������ �հ�
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
//	// ���� ���� = �߽���ǥ �� ������ ��������
//	// �߽���ǥ-���� ���������� ������ ũ�� �� 2���� 0�̻��� ���, 2���� 0������ ������ ��Ÿ��
//	// �ش� ���� �� ����� �κа� ������ �κ��� ���Ͽ� ����
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