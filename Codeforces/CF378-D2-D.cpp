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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9 , si = 100005;
int n, m, s, k, ans[si];
pair<int, pair<int,int> > st[si];
pair<int, int> a[si];
bool valid(int mid){
	multiset<pair<int, pair<int, int> > > ms , op;
	multiset<pair<int, pair<int,int> > >::iterator it;
	ll cs = s , bk = n - 1;
	for (int i = m - 1; i >= 0; i--){
		while (bk >= 0){
			if (a[i].first <= st[bk].first){
				ms.insert(MP(st[bk].second.first, MP(st[bk].second.second, 0)));
				bk--;
			}
			else break;
		}
		if (ms.size() == 0 && op.size() == 0) return 0;
		if (op.size() != 0){
			ans[a[i].second] = op.begin()->second.first;
			pair<int, pair<int, int> > p(*op.begin());
			op.erase(op.begin());
			if (p.second.second + 1 < mid)
				op.insert(MP(p.first, MP(p.second.first, p.second.second + 1)));
		}
		else {
			cs -= ms.begin()->first;
			if (cs < 0) return 0;
			pair<int, pair<int, int> > p(*ms.begin());
			if (p.second.second + 1 < mid)
				op.insert(MP(p.first, MP(p.second.first, p.second.second + 1)));
			ms.erase(ms.begin());
			ans[a[i].second] = p.second.first;
		}
	}
	return 1;
}
int main()
{
	Emsawy();
	while (cin >> n >> m >> s){
		for (int i = 0; i < m; i++) sf(a[i].first) , a[i].second = i;
		for (int i = 0; i < n; i++) sf(st[i].first), st[i].second.second = i;
		for (int i = 0; i < n; i++) sf(st[i].second.first);
		sort(st, st + n);
		sort(a, a + m);
		int s = 0, e = m + 10, res = -1;
		while (s <= e){
			int mid = (s + e) >> 1;
			if (valid(mid)) e = mid - 1, res = mid;
			else s = mid + 1;
		}
		if (res == -1){
			cout << "NO" << endl;
			continue;
		}
		valid(res);
		cout << "YES" << endl;
		for (int i = 0; i < m; i++)
			cout << ans[i] + 1 << " \n"[i == m - 1];
	}
	return 0;
}
