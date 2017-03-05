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
struct q{
	int A, B, K, lo, hi;
};
bool comp(V<int> & a, V<int> & b){
	if (a.size() < b.size()) return 1;
	else if (b.size() < a.size()) return 0;
	if (a < b)return 1;
	return 0;
}

const int si = 1001000;
V<int>g[si];
int op[si], p[si] ,ml[si];
void sieve(){
	op[0] = op[1] = 1;
	for (ll i = 2; i < si; i++){
		if (op[i]) continue;
		op[i] = i;
		for (ll j = i * i; j < si; j += i){
			if (op[j]) continue; // sorted prime factors
			op[j] = i;
		}
	}
	for (int i = 2; i < si; i++){
		int now = i;
		while (now > 1){
			g[i].push_back(op[now]);
			now /= op[now];
		}
	}
	sort(g, g + si, comp);
	for (int i = 0; i < si; i++){
		int now = 1;
		for (int j = 0; j < g[i].size(); j++)
			now *= g[i][j];
		ml[i] = now;
	}
}
q eq[si];
V<int> quary[si + 10];
int BIT[si + 10] , ans[si + 10];
void update(int idx, int vl){
	while (idx < si + 10){
		BIT[idx] += vl;
		idx += (idx & -idx);
	}
}

int get(int idx){
	int sum = 0;
	while (idx > 0){
		sum += BIT[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int main()
{
	Emsawy();
	sieve();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		sf3(eq[i].A, eq[i].B, eq[i].K);
		eq[i].lo = 2;
		eq[i].hi = si;
		quary[(eq[i].lo + eq[i].hi) / 2].push_back(i);
	}
	for (int i = 0; i < 25; i++){
		for (int j = 2; j < si; j++){
			update(ml[j], 1);
			while (quary[j].size()){
				int now = get(eq[quary[j].back()].B) - get(eq[quary[j].back()].A - 1);
				if (now >= eq[quary[j].back()].K){
					ans[quary[j].back()] = j;
					eq[quary[j].back()].hi = j - 1;
					if (eq[quary[j].back()].lo <= eq[quary[j].back()].hi)
						quary[(eq[quary[j].back()].lo + eq[quary[j].back()].hi) / 2].push_back(quary[j].back());
				}
				else {
					eq[quary[j].back()].lo = j + 1;
					if (eq[quary[j].back()].lo <= eq[quary[j].back()].hi)
						quary[(eq[quary[j].back()].lo + eq[quary[j].back()].hi) / 2].push_back(quary[j].back());
				}
				quary[j].pop_back();
			}
		}
		clr(BIT, 0);
	}
	int c = 1;
	for (int i = 0; i < n; i++){
		int an = ans[i];
		printf("Case %d:" ,c++);
		for (int j = 0; j < g[an].size(); j++){
			printf(" %d", g[an][j]);
		}
		puts("");
	}

	return 0;
}
