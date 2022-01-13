/*
	����� 1
	���� 1259�� �Ӹ���Ҽ�
	��ó - 2006 ICPC ��������
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	while(true)
	{
		bool flag = true;
		cin >> input;
		if(input == "0")
			break;

		int length = input.length();
		for(int i = 0; i < length / 2; ++i)
		{
			if(input[i] != input[length - i - 1])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}