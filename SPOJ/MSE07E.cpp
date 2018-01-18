
/*

http://d.hatena.ne.jp/komiyam/20120207/1328545633
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
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
const ll N = 100000 + 5;
int n, m, k, w, q;
string s;
char buf[1025];
ll now[5000000][3];

bool init(){
	int f = 0;
	n = 0;
	while ((f = ((gets(buf) != NULL))) && strlen(buf) > 2){
		sscanf(buf, "%lld%lld%lld", now[n], now[n] + 1, now[n] + 2);
		n++;
	}

	return f || n > 0;
}
ll get(ll a, ll b, ll c){
	return (b - a) / c + 1;
}
bool valid(ll mid){
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if (mid >= now[i][1])
			ans += get(now[i][0], now[i][1], now[i][2]);
		else if (mid >= now[i][0])
			ans += get(now[i][0], mid, now[i][2]);
	}
	return (ans & 1) > 0;
}
void solve(){
	if (!n) return;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += get(now[i][0], now[i][1], now[i][2]);
	}
	if (!(ans & 1)){
		puts("no corruption");
		return;
	}
	ll s = 0, e = 1LL << 40;
	while (s < e){
		ll mid = e - (e - s + 1) / 2;
		if (valid(mid)) e = mid;
		else s = mid + 1;
	}
	ans = 0;
	for (int i = 0; i < n; i++){
		if (e <= now[i][1] && e >= now[i][0] && (e - now[i][0]) % now[i][2] == 0){
			ans++;
		}
	}
	cout << e << " " << ans << endl;
}
int main(){
	Emsawy();
	while (init()){
		solve();
	}
	return 0;
}
