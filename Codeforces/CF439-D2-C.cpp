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

V<V<int> > adj;
const ll N = 100000 + 5;
ll n, m, k, w;

int main() {

	Emsawy();
	int p;
	while (cin >> n >> k >> p){
		V<int>even, odd;
		for (int i = 0; i < n; i++){
			cin >> m;
			if (m % 2) odd.push_back(m);
			else even.push_back(m);
		}
		int rem = max(0, p - (int)even.size());
		int oddN = odd.size() - rem * 2;
		if (oddN < k - p || (oddN - (k - p)) % 2){
			cout << "NO" << endl;
			continue;
		}
		V<V<int> > K(k - p), P(p);
		for (int i = 0; i < P.size(); i++){
			if (even.size() == 0){
				P[i].push_back(odd.back()); odd.pop_back();
				P[i].push_back(odd.back()); odd.pop_back();
				continue;
			}
			P[i].push_back(even.back()); even.pop_back();
		}
		while (even.size()){
			if (P.size()) P[0].push_back(even.back()), even.pop_back();
			else K[0].push_back(even.back()), even.pop_back();
		}
		for (int i = 0; i < K.size(); i++){
			K[i].push_back(odd.back()); odd.pop_back();
		}
		while (odd.size()){
			if (P.size()) {
				P[0].push_back(odd.back()), odd.pop_back();
				P[0].push_back(odd.back()), odd.pop_back();
			}
			else{
				K[0].push_back(odd.back()), odd.pop_back();
				K[0].push_back(odd.back()), odd.pop_back();
			}
		}
		cout << "YES" << endl;
		for (int i = 0; i < P.size(); i++){
			cout << P[i].size() << " ";
			for (int j = 0; j < P[i].size(); j++){
				cout << P[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < K.size(); i++){
			cout << K[i].size() << " ";
			for (int j = 0; j < K[i].size(); j++){
				cout << K[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
