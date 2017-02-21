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

#define sz(v) ((int)((v).size()))
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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k;
const int MAXP = 100005;
map<int,int> Pr[MAXP];
int vl[MAXP];
void sieve(){
	for (int i = 2; i < MAXP; i++) vl[i] = i;
	for (ll i = 2; i < MAXP; i++){
		if (Pr[i].size()) continue;
		int st = 0;
		for (ll j = i; j < MAXP; j += i){
			while (vl[j] % i == 0)++st, vl[j] /= i;
			Pr[j][i] = st;
		}
	}
}
map<int,int> g;
void PrimeFactors(ll me){
	for (int i = 2; (ll)i * i <= me; i++){
		while (me % i == 0)
			me /= i, g[i]++;
	}
	if (me > 1) g[me]++;
}

int main()
{
	Emsawy();
	sieve();
	while (cin >> n >> m){
		g.clear();
		PrimeFactors(m);
		n--;
		V<int>ans;
		for (int i = 0; i <= n; i++){
			bool ok = 1;
			for (auto it : g){
				if (Pr[(n/it.first) * it.first][it.first] - Pr[((n - i)/it.first)*it.first][it.first] - Pr[(i / it.first)* it.first][it.first] < it.second){
					ok = 0;
					break;
				}
			}
			if (ok) ans.push_back(i + 1);
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d%s", ans[i], i == ans.size() - 1 ? "" : " ");
		}
		puts("");
	}
	return 0;

}
