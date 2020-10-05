#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define unicos(X) (X).erase(unique(all(X)),(X).end())
#define NL <<"\n"
#define EPS 1e-6
#define MOD 1000000007
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

int k;
vector<int> pai[112345];
vector<int> grid[112345];
int parent[112345];
int visited[112345];
int n;
stack<int> s;
void dfs (int u, int par)
{
    visited[u]=1;
    for (auto v: grid[u])
    {
        if (!visited[v])
            dfs(v, u);
    }
    s.push(u);
}

void _dfs()
{
    memset(parent, -1, sizeof parent);
    memset(visited, 0, sizeof visited);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i, -1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int w;
        cin >> w;
        for (int j = 0; j < w; ++j)
        {
            int x;
            cin >> x;
            x--;
            grid[i].pb(x);
            pai[x].pb(i);
        }
    }
    _dfs();
    // int boss = s.top();
    // s.pop();
    // parent[boss] = -1;
    int prev = -1;
    while (!s.empty())
    {
        int v = s.top();
        // printf("%d ",v+1 );
        s.pop();
        parent[v] = prev;
        prev=v;
    }
    // printf("\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n",parent[i]+1 );
    }
    return 0;
}
