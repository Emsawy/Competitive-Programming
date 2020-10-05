#include <bits/stdc++.h>

using namespace std;

int amigos[1010][1010];
int visitados[1010];
int times;

int dfs(int v, int n)
{
	if (visitados[v])
		return 0;
	visitados[v]=1;
	for (int i = 0; i < n; ++i)
	{
		if (amigos[v][i])
			dfs(i,n);
	}
	return 1;

}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	times = 0;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		amigos[a-1][b-1]=amigos[b-1][a-1]=1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += dfs(i,n);
	}
	printf("%d\n",ans );

	return 0;
}