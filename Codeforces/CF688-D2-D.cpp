#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
const ll N = 4e2 + 5;
int n, m, k, w, h;

const int MAXP = 1000006;
int Pr[MAXP];
void sieve(){
	Pr[0] = Pr[1] = 1;
	for (ll i = 2; i < MAXP; i++){
		if (Pr[i]) continue;
		Pr[i] = i;
		for (ll j = i*i; j < MAXP; j += i){
			Pr[j] = i;
		}
	}
}

int mp[2][MAXP];
void lcm(int x, int dir){
	while (x > 1){
		int now = Pr[x], cnt = 0;
		while (x % now == 0 && x > 1) cnt++, x /= now;
		mp[dir][now] = max(mp[dir][now], cnt);
	}
}

int main() {

	Emsawy();
	sieve();
	while (cin >> n >> k){
		int v;
		for (int i = 0; i < n; i++){
			cin >> v;
			lcm(v, 0);
		}
		lcm(k, 1);
		bool ok = 0;
		for (int i = 0; i < MAXP;i++){
			if (mp[0][i] < mp[1][i]){
				ok = 1;
				break;
			}
		}
		if (ok == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
} 
