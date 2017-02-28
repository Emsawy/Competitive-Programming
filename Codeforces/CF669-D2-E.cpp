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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9, e = 19;
int n, m, k ;
#define me pair<int,pair<int,int> > 
map<int,int> tr[(1 << e) + 1] , idx; // 1e6
void update(int p, int l, int r, int x, int y , int vl , int op){
	if (l > y || r < x)
		return;
	if (x <= l && r <= y){
		tr[p][vl] += op;
		return;
	}
	tr[p][vl] += op;
	int mid = (l + r) / 2;
	if (y <= mid)
		update(p * 2, l, (l + r) / 2, x, y, vl, op);
	else
		update(p * 2 + 1, (l + r) / 2 + 1, r, x, y, vl, op);
}
ll get(int p, int l, int r, int x, int y,int vl){
	if (l > y || r < x)
		return 0;
	if (x <= l && r <= y)
		return tr[p][vl];

	return get(p * 2, l, (l + r) / 2, x, y , vl) + get(p * 2 + 1, (l + r) / 2 + 1, r, x, y , vl);
}
int main()
{
	Emsawy();
	while (cin >> n){
		int a, b, c , id = 1;
		V<me>v(n);
		V<int>t(n);
		for (int i = 0; i < n; i++){
			sf3(v[i].first, v[i].second.first, v[i].second.second);
			t[i] = v[i].second.first;
		}
		sort(all(t));
		for (int i = 0; i < n; i++)
			idx[t[i]] = id++;

		for (int i = 0; i < n; i++){
			if (v[i].first == 1) update(1, 1, id, idx[v[i].second.first], idx[v[i].second.first], v[i].second.second, 1);
			else if (v[i].first == 2)update(1, 1, id, idx[v[i].second.first], idx[v[i].second.first], v[i].second.second, -1);
			else printf("%d\n", get(1, 1, id, 1, idx[v[i].second.first], v[i].second.second));
		}
		for (int i = 0; i < (1 << e) + 1; i++)
			tr[i].clear();
		idx.clear();
	}
	return 0;
}
