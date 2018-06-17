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

V<V<int> > g1, g2;
const ll N = 100000 + 5;
int n, m, k, w;
string s1, s2;
int s = 0;

void go_1(int nd) {
	while (s < s1.size() && s1[s] == '0') {
		g1.resize(g1.size() + 1);
		g1[nd].push_back(g1.size());
		s++;
		go_1(g1.size());
		s++;
	}
}

void go_2(int nd) {
	while (s < s2.size() && s2[s] == '0') {
		g2.resize(g2.size() + 1);
		g2[nd].push_back(g2.size());
		s++;
		go_2(g2.size());
		s++;
	}
}

string canon(V<V<int> > & g, int nd) {

	V<string> ret;
	for (int i = 0; i < g[nd].size(); i++) {
		ret.push_back(canon(g, g[nd][i]));
	}
	sort(all(ret));
	string res = "(";
	for (int i = 0; i < ret.size(); i++) {
		res += ret[i];
	}
	res += ")";
	return res;
}

void repair(V<V<int> > &g) {
	int mx = 0;
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			mx = max(mx, g[i][j]);
		}
	}
	g.resize(mx + 1);
}
int main() {

	Emsawy();
	cin >> n;
	while (n--) {
		cin >> s1 >> s2;
		g1.clear();
		g2.clear();
		s = 0;
		go_1(0);
		s = 0;
		go_2(0);
		repair(g1);
		repair(g2);
		if (canon(g1, 0) == canon(g2, 0)) {
			cout << "same" << endl;
		}
		else {
			cout << "different" << endl;
		}
	}
	return 0;
}
