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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e7;
int n, m, g[102];
V<int >primes;
V<V<int> > lop;
int dp[101][(1 << 16) + 10];
int go(int id, int mask){
	if (id == n)
		return 0;
	int &ret = dp[id][mask];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, go(id + 1, mask) + g[id] - 1);
	for (int i = 2; i < lop.size(); i++){
		int ok = 0, xr = 0;
		for (int j = 0; j < lop[i].size(); j++){
			xr |= (1 << lop[i][j]);
			if (((mask >> lop[i][j]) & 1)) {
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		ret = min(ret, go(id + 1, mask | xr) + abs(i - g[id]));
	}
	return ret;
}
V<int>ans;
void getPath(int id, int mask){
	if (id == n)
		return;
	if (dp[id][mask] == go(id + 1, mask) + g[id] - 1){
		ans.push_back(1);		
		getPath(id + 1, mask);
		return;
	}
	for (int i = 2; i < lop.size(); i++){
		int ok = 0, xr = 0;
		for (int j = 0; j < lop[i].size(); j++){
			xr |= (1 << lop[i][j]);
			if (((mask >> lop[i][j]) & 1)) {
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		if (dp[id][mask] == go(id + 1, mask | xr) + abs(i - g[id])){
			ans.push_back(i);
			getPath(id + 1, mask | xr);
			return;
		}
	}
}
bool isprime(int x){
	if (x <= 1) return 0;
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0)
			return 0;
	}
	return 1;
}
void getPrimes(){
	int st = 2;
	while (primes.size() < 16){
		if (isprime(st))
			primes.push_back(st);
		st++;
	}
}
void getFactors(){
	lop.push_back(V<int>());
	for (int i = 1; i <= 60; i++){
		lop.push_back(V<int>());
		for (int j = 0; j < primes.size(); j++){
			if (i % primes[j] == 0){
				lop.back().push_back(j);
			}
		}
	}
}

int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++)
			sf(g[i]);
		getPrimes();
		getFactors();
		clr(dp, -1);
		int ret = go(0, 0);
		getPath(0, 0);
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		puts("");
		ans.clear();
		primes.clear();
		lop.clear();
	}
	return 0;
}
