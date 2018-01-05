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
const ll N = 200000 + 5;
int n, m, k, w, p;
int vn[N], vm[N];
map<int, int> L;
multiset<pair<int, int> > done;

bool isOk(int pos){
	if (pos + (m - 1) * p <= n) return 1;
	return 0;
}
int Next(int pos){
	return pos + p;
}
bool upd_1(int j){
	set<pair<int, int> >::iterator it = done.find(MP(L[vn[j]], vn[j]));
	if (it == done.end()) return 0;
	pair<int, int> cur = *it;
	cur.first--;
	done.erase(it);
	done.insert(cur);
	L[vn[j]]--;
	return 1;
}
bool upd_2(int j){
	set<pair<int, int> >::iterator it = done.find(MP(L[vn[j]], vn[j]));
	if (it == done.end()) return 0;
	pair<int, int> cur = *it;
	cur.first++;
	done.erase(it);
	done.insert(cur);
	L[vn[j]]++;
	return 1;
}
int main() {

	Emsawy();
	while (cin >> n >> m >> p){
		for (int i = 1; i <= n; i++) cin >> vn[i];
		for (int i = 1; i <= m; i++) cin >> vm[i];

		for (int i = 1; i <= m; i++){
			L[vm[i]] ++;
		}
		for (auto it : L){
			done.insert(MP(it.second, it.first));
		}
		V<int>ans;
		for (int i = 1; i <= p; i++){
			if (!isOk(i)) continue;
			int lst = i;
			for (int j = i; j <= n; j = Next(j)){
				if (!upd_1(j)) ;
				if ((j - i) / p >= (m - 1)){
					lst = j - (m - 1) * p;
					if (done.begin()->first <= 0 && (--done.end())->first <= 0){
						ans.push_back(lst);
					}
					upd_2(lst);
				}
			}
			while (Next(lst) <= n){
				lst = Next(lst);
				if (!upd_2(lst)) ;
			}
		}
		sort(all(ans));
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		L.clear();
		done.clear();
	}
	return 0;
}
