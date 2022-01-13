/*
	실버5
	백준 10814번 나이순 정렬
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct person
{
	int age;
	string name;
};

bool compare(const person& a, const person& b)
{
	return a.age < b.age;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	person* list = new person[n];

	for(int i = 0; i < n; ++i)
	{
		cin >> list[i].age >> list[i].name;
	}

	// 정렬
	stable_sort(list, list + n, compare);

	for(int i = 0; i < n; ++i)
	{
		cout << list[i].age << ' ' << list[i].name << '\n';
	}

	delete[] list;
	return 0;
}