/*
	골드 4
	백준 1922번 네트워크 연결
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

	s[a] += s[b];
	l[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;	

	l = vector<int>(n);
	s = vector<int>(n);
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
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			answer += e.value;
		}
	}

	cout << answer;

	return 0;
}