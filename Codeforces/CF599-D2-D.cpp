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

V<V<int> > adj;
const ll N = 1900120;
ll n, m, k, w;
ll dp[N];

ll valid(ll i, ll mid){
	ll ret = dp[i];
	ll suf = (i * (i + 1)) / 2;
	if ((mid - i) > 2e18 / suf) return 2e18;
	suf *= (mid - i);
	if (ret > 2e18 - suf) return 2e18;
	return ret + suf;
}
int main() {

	Emsawy();
	dp[1] = 1;
	for (int i = 2; i < N; i++){
		dp[i] += dp[i - 1];
		dp[i] += i * 1LL * i;
	}
	while (cin >> n){
		V<pair<ll, ll> > ans;
		for (int i = 1; i < N; i++){
			ll s = i, e = n;
			while (s < e){
				ll mid = s + (e - s + 1) / 2;
				if (valid(i, mid) <= n) s = mid;
				else e = mid - 1;
			}
			if (valid(i, s) == n){
				ans.push_back(MP(i, s));
			}
		}
		int size = ans.size() * 2;
		if (ans.back().first == ans.back().second) size--;
		cout << size << endl;
		for (int i = 0; i < ans.size(); i++){
			printf("%lld %lld\n", ans[i].first, ans[i].second);
		}
		for (int i = ans.size() - 1 - (size & 1); i >= 0; i--){
			cout << ans[i].second << " " << ans[i].first << endl;
		}
	}
	return 0;
}
