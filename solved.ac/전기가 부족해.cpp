/*
	골드 2
	백준 10423번 전기가 부족해
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int u;
	int v;
	int value;
};
vector<Edge> edges;

vector<int> l;
vector<int>	s;
vector<bool> power_plant;

int find(int x)
{
	if (x == l[x])
		return x;

	return l[x] = find(l[x]);
}

bool same(int a, int b)
{
	return find(a) == find(b);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if (s[a] < s[b])
		swap(a, b);

	if (power_plant[b])
		swap(a, b);

	s[a] += s[b];
	l[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	l = vector<int>(n);
	s = vector<int>(n);
	power_plant = vector<bool>(n);
	while (k--)
	{
		int i;
		cin >> i;

		power_plant[--i] = true;
	}

	edges = vector<Edge>(m);

	for (int i = 0; i < n; ++i)
	{
		l[i] = i;
		s[i] = 1;
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v, value;
		cin >> u >> v >> value;

		edges[i] = { --u, --v, value };
	}
	sort(edges.begin(), edges.end(),
		[](Edge a, Edge b)
		{
			return a.value < b.value;
		}
	);

	int answer = 0;
	for (Edge e : edges)
	{
		int a = find(e.u);
		int b = find(e.v);
		
		if (power_plant[a] && power_plant[b])
			continue;

		if (a != b)
		{
			unite(e.u, e.v);
			answer += e.value;
		}
	}

	cout << answer;

	return 0;
}