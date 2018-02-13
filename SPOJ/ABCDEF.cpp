#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
const ll N = 111;
int n, m, k, w;
ll a[N];

int main() {

	Emsawy();
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++){
			scanf("%lld", &a[i]);
		}
		unordered_map<ll, int > mp;
		unordered_map<ll, int >::iterator it;
		mp.reserve(16000000);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					mp[a[i] * a[j] + a[k]]++;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					if (a[k] == 0) continue;
					ans += mp[(a[i] + a[j]) * a[k]];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
