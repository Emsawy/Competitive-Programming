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

		V<int>v(n), odd;
		V<V<int> > P(p), K(k - p);
		int st = 0;
		bool ans = 0;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			if (v[i] % 2 == 0){
				if (P.size() == 0) continue;
				P[st].push_back(v[i]);
				st += 1;
				st %= P.size();
			}
		}
		if (P.size() == 0){
			int st = 0;
			for (int i = 0; i < n; i++){
				if (v[i] % 2 == 1){
					if (st == K.size()){
						odd.push_back(v[i]);
						continue;
					}
					K[st].push_back(v[i]);
					st++;
				}
				else
					K[0].push_back(v[i]);
			}
			if (odd.size() % 2 || st < K.size()) {
				cout << "NO" << endl;
				continue;
			}
			while (odd.size()){
				K[0].push_back(odd.back()); odd.pop_back();
				K[0].push_back(odd.back()); odd.pop_back();
			}
			cout << "YES" << endl;
			for (int i = 0; i < K.size(); i++){
				cout << K[i].size() << " ";
				for (int j = 0; j < K[i].size(); j++)
					cout << K[i][j] << " ";
				cout << endl;
			}
			continue;
		}
		bool ok = 0;
		for (int i = 0; i < P.size();i++)
			if (P[i].size() == 0)
				ok = 1;
			
		for (int i = 0; i < n; i++){
			if (v[i] % 2)
				odd.push_back(v[i]);
		}
		if (ok){
			for (int i = 0; i < P.size(); i++){
				if (P[i].size() == 0){
					if (odd.size() < 2){
						ans = 1;
						break;
					}
					P[i].push_back(odd.back()); odd.pop_back();
					P[i].push_back(odd.back()); odd.pop_back();
				}
			}
		}
		for (int i = 0; i < K.size(); i++){
			if (odd.size() == 0){
				ans = 1;
				break;
			}
			K[i].push_back(odd.back());
			odd.pop_back();
		}
		while(odd.size()){
			if (odd.size() < 2){
				ans = 1;
				break;
			}
			if (P.size()){
				P[0].push_back(odd.back()); odd.pop_back();
				P[0].push_back(odd.back()); odd.pop_back();
			}
			else {
				K[0].push_back(odd.back()); odd.pop_back();
				K[0].push_back(odd.back()); odd.pop_back();
			}
		}
		if (ans){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < P.size(); i++){
			cout << P[i].size() << " ";
			for (int j = 0; j < P[i].size(); j++)
				cout << P[i][j] << " ";
			cout << endl;
		}
		for (int i = 0; i < K.size(); i++){
			cout << K[i].size() << " ";
			for (int j = 0; j < K[i].size(); j++)
				cout << K[i][j] << " ";
			cout << endl;
		}

	}
	return 0;
}
