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
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<pair<int,int> > > adj;
const ll N = 5000 + 5;
long double eps = 1e-15;
ll n, m, k, w, q;

int main() {

	Emsawy();
	while (cin >> n){
		V<int>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		stack<pair<int,int> >st;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (st.empty()){
				st.push(MP(v[i], 0));
				continue;
			}
			int mx = 0;
			while (st.size() && st.top().first < v[i]){
				mx = max(mx, st.top().second);
				st.pop();
			}
			if (st.empty()){
				st.push(MP(v[i], 0));
				continue;
			}
			ans = max(ans, mx + 1);
			st.push(MP(v[i], mx + 1));
		}
		cout << ans << endl;
	}
	return 0;
}
