#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = 1e9 + 7, oo = 1e9;
int n, m;
const int MAXP = 2000000;
int p[MAXP + 1] , g[MAXP + 1];
V<pair<int, int> > mp;
void sieve(){
	for (int i = 1; i <= MAXP; i++)
		g[i] = i;
	p[0] = p[1] = 1;
	for (ll i = 2; i <= MAXP; i++){
		if (p[i]) continue;
		for (ll j = i; j <= MAXP; j += i){
			while (g[j] % i == 0) 
			g[j] /= i, p[j]++;
		}
	}
	for (int i = 1; i <= MAXP; i++)
		mp.push_back(MP(p[i], i));
	sort(all(mp));
}

int main()
{
	Emsawy();
	sieve();
	int c = 1;
	while (cin >> n){
		if (n == 0) break;
		printf("Case %d: %d\n", c++, mp[n - 1].second);
	}
	return 0;
}
