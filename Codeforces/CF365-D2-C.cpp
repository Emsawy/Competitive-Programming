#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1e17;

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
const ll N = 4000 + 5;
int n, m, k, w;
string s;
int main() {

	Emsawy();
	while (cin >> k >> s){
		map<int, int>mp;
		for (int i = 0; i < s.size(); i++){
			int sum = 0;
			for (int j = i; j < s.size(); j++){
				sum += (s[j] - '0');
				mp[sum]++;
			}
		}
		
		ll ans = 0;
		for (auto it : mp){
			if (it.first == 0){
				if (k != 0) continue;
				ll now = ((s.size() * (s.size() + 1)) / 2) * 1LL * it.second;
				ans += now;
				continue;
			}
			if (k % it.first == 0){
				map<int, int>::iterator itt = mp.find((k / it.first));
				if (itt == mp.end()) continue;
				ll now = itt->second * 1LL * it.second;
				ans += now;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
