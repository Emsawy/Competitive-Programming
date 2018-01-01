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
const ll N = 100000 + 5;
ll n, m, k, w;

struct cmp{
	// -> f , -> s
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if (a.first > b.first) return 1;
		else if (a.first == b.first && a.second > b.second) return 1;
		return 0;
	}
};


int main() {

	Emsawy();
	while (cin >> n >> k){
		cin >> m;
		multiset<pair<int,int> ,cmp > st;
		V<int>v(n);
		ll sum = 0;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			if (i != n - 1)
			st.insert(MP(v[i],i));
		}
		int cnt = k, lst = 0;
		map<int, bool>with;
		for (auto it : st){
			if (cnt <= 0) break;
			cnt--;
			lst = it.first;
			sum += lst;
			with[it.second] = 1;
		}
		int ans = n - 1;
		for (int i = 0; i < n - 1; i++){
			if (with[i]){
				if (sum > m)
					ans = min(ans,i);
			}
			else{
				sum -= lst;
				sum += v[i];
				if (sum > m) ans = min(ans,i);
				sum += lst;
				sum -= v[i];
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
