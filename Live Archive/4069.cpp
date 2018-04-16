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

const ll N = 1124;
int n, m, k, w, h;
int conv(string s) {
	int pw = 1, ret = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ret += (pw * (s[i] - '0'));
		pw *= -2;
	}
	return ret;
}
set<pair<int, string> > st;
void gen(int id, string s, int res) {
	if (id >= 20) {
		st.insert(MP(res, s));
		return;
	}
	gen(id + 1, s + '0', res);
	gen(id + 1, s + '1', res + (1 << id) * ((id & 1) ? -1 : 1));
}
int main() {

	Emsawy();
	string s;
	int d;
	gen(0, "", 0);
	scanf("%d", &n);
	char ch;
	for (int i = 0; i < n; i++) {
		scanf("\n%c ", &ch);
		if (ch == 'b') {
			cin >> s;
			printf("From binary: %s is %d\n", s.c_str(), conv(s));
		}
		else {
			cin >> d;
			s = st.lower_bound(MP(d, ""))->second;
			while (s.size() && s.back() == '0') s.pop_back();
			reverse(all(s));
			if (s == "") s = "0";
			printf("From decimal: %d is %s\n",d, s.c_str());
		}
	}
	return 0;
}
