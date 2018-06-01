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
const ll N = 1000 + 5;
ll n, m, k, w;
string t[16];
double g[16][16];
bool ord[16];
pair< V<pair<double , int > > , bool> u[16 * 16];

void go(int id, int s, int e) {
	u[id].first.clear();
	u[id].second = 0;
	if (s == e) {
		u[id].first.push_back(MP(1, s));
		u[id].second = ord[s];
		return;
	}
	go(id * 2, s, (s + e) / 2);
	go(id * 2 + 1, (s + e) / 2 + 1, e);
	pair< V<pair<double, int > >, bool> &l = u[id * 2];
	pair< V<pair<double, int > >, bool> &r = u[id * 2 + 1];
	pair< V<pair<double, int > >, bool> ret;

	if (r.second)
		swap(l, r);

	if (l.second) {
		for (int i = 0; i < l.first.size(); i++) {
			for (int j = 0; j < r.first.size(); j++) {
				ret.first.push_back(MP(l.first[i].first * g[l.first[i].second][r.first[j].second] * r.first[j].first, l.first[i].second));
			}
		}
		ret.second = 1;
	}
	else {
		for (int i = 0; i < l.first.size(); i++) {
			for (int j = 0; j < r.first.size(); j++) {
				ret.first.push_back(MP(l.first[i].first * g[l.first[i].second][r.first[j].second] * r.first[j].first, l.first[i].second));
				ret.first.push_back(MP(l.first[i].first * g[r.first[j].second][l.first[i].second] * r.first[j].first, r.first[j].second));
			}
		}
	}
	u[id] = ret;
}

int main() {

	Emsawy();
	for (int i = 0; i < 16; i++)
		cin >> t[i];
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cin >> w;
			g[i][j] = w / 100.0;
		}
	}
	V<double> ans;
	for (int i = 0; i < 16; i++) {
		ord[i] = 1;

		go(1, 0 , 15);
		double ret = 0;
		for (int j = 0; j < u[1].first.size(); j++) {
			ret += u[1].first[j].first;
		}
		ans.push_back(ret * 100);
		ord[i] = 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		while (t[i].size() < 10) t[i] += ' ';
		cout <<fixed << setprecision(2)<< t[i] << " p=" << ans[i] <<"%"<< endl;
	}

	return 0;
}






