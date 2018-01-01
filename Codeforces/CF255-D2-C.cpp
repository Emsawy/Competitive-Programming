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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pair<int,int> > > adj;
const ll N = 4000 + 5;
ll n, m, k, w;
int dp[N][N];

int main() {

	Emsawy();
	while (cin >> n){
		V<int>v(n+1);
		map<int, int>cord;
		for (int i = 1; i <= n; i++){
			cin >> v[i];
			cord[v[i]];
		}
		int start = 1;
		for (map<int, int>::iterator it = cord.begin(); it != cord.end(); it++)
			it->second = start++;
		for (int i = 1; i <= n; i++)
			v[i] = cord[v[i]];

		for (int i = 1; i <= n; i++){
			for (int j = 1; j < N; j++){
				dp[v[i]][j] = max(dp[v[i]][j] , dp[j][v[i]] + 1);
			}
		}
		int ans = 0;
		for (int i = 1; i < N; i++){
			for (int j = 1; j < N; j++)
				ans = max(ans, dp[i][j]);
		}
		cout << ans << endl;
	}
	return 0;
}

/*
// Brute force solution
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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pair<int, int> > > adj;
const ll N = 1000000 + 5;
ll n, m, k, w;
map<int, V<int> > mp;
int valid(V<int>&a, V<int>&b){
	int ret = 0;
	int sa = 0, sb = 0, idx = -1;
	for (sa = 0; sa < a.size(); sa++){
		if (idx < a[sa]){
			idx = a[sa];
			ret++;
			bool ok = 0;
			for (; sb < b.size(); sb++){
				if (idx < b[sb]){
					ok = 1;
					idx = b[sb];
					ret++;
					break;
				}
			}
			if (ok == 0) return ret;
		}
	}
	return ret;
}
int main() {

	Emsawy();
	while (cin >> n){
		V<int>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			mp[v[i]].push_back(i);
		}
		int ans = 0;
		for (map<int, V<int> > ::iterator a = mp.begin(); a != mp.end(); a++){
			for (map<int, V<int> > ::iterator b = a; b != mp.end(); b++){
				if (a->first == b->first) ans = max(ans, (int)a->second.size());
				else ans = max(ans, max(valid(b->second, a->second), valid(a->second, b->second)));
			}
		}
		cout << ans << endl;
	}
	return 0;
}

*/
