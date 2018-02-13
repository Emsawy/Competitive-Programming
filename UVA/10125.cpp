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

V<V<int> > adj;
const ll N = 100000 + 5;
int n, m, k, w;

int main() {

	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		w++;
		if (w == 8){
			int st = 0;
		}
		V<int>v(n);
		map<int, V<pair<int, int> > > mp;
		map<int, V<pair<int, int> > >::iterator it;
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(allr(v));
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				mp[v[i] + v[j]].push_back(MP(i, j));
			}
		}
		bool ok = 1;
		for (int i = 0; i < n && ok; i++){
			for (int j = 0; j < n && ok; j++) if (i != j){
				it = mp.find(v[i] - v[j]);

				if (it != mp.end()){
					if (it->second.size() > 2){
						cout << v[i] << endl;
						ok = 0;
						break;
					}
					for (int k = 0; k < it->second.size(); k++){
						if (it->second[k].first != i && it->second[k].first != j && it->second[k].second != i && it->second[k].second != j){
							cout << v[i] << endl;
							ok = 0;
							break;
						}
					}
				}
			}
		}
		if (ok){
			cout << "no solution" << endl;
		}
	}
	return 0;
}

