#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<pair<int,int> > > adj;
const ll N = 1100 + 5;
int n, m, k, w, h;
int in[N][N];
int path[N];
int nodes[N];
int g[N];
char s[N];
void cal(int src, int sink){
	int l = nodes[src], r = nodes[sink];
	nodes[src] = nodes[sink] = 0;
	clr(path, 0);
	fill(g, g + N, oo);
	priority_queue<pair<int, int>, V<pair<int,int> > , greater<pair<int, int> > > pq;
	pq.push(MP(0, src));
	g[src] = 0;
	while (pq.empty() == false){
		pair<int, int> p = pq.top();
		pq.pop();
		for (int i = 1; i <= n; i++){
			if (in[p.second][i] == -1 || g[i] <= p.first + in[p.second][i] + nodes[i]) continue;
			g[i] = p.first + in[p.second][i] + nodes[i];
			path[i] = p.second;
			pq.push(MP(g[i], i));
		}
	}
	nodes[src] = l;
	nodes[sink] = r;
	int tot = g[sink];
	printf("From %d to %d :\n", src, sink);
	printf("Path: ");
	V<int>ans;
	while (path[sink] != 0){
		ans.push_back(sink);
		sink = path[sink];
	}
	ans.push_back(src);
	for (int i = ans.size() - 1; i >= 0; i--){
		if (i)
			printf("%d-->", ans[i]);
		else
			printf("%d", ans[i]);
	}
	printf("\nTotal cost : %d\n", tot);
}
int main() {

	Emsawy();
	int t, pr = 0;
	scanf("%d\n", &t);
	while (t--){
		stringstream sin;
		n = 1;
		gets(s);
		sin << s;
		while (sin >> in[1][n++]);
		n-= 2;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &in[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &nodes[i]);
		getchar();
		int u, v, ok = 0;
		while (gets(s) && strlen(s) != 0){
			if(ok) puts("");
			ok = 1;
			sscanf(s, "%d %d\n", &u, &v);
			cal(u, v);
		}
		
		if(t) puts("");
	}
	return 0;
}
