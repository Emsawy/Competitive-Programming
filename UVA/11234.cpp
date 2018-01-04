
/*
If we construct the input string as a tree will notice that the answer is the sum of the letters of same levels reversed from down to up.
Example:

xyPzwIM

        M         level -> 0
    P       I     level -> 1
 x    y   z    w  level -> 2

sum of level 2 -> w + z + y + x -> wzyx
sum of level 1 -> I + P -> IP
sum of level 0 -> M -> M

sum from down to up , 2 -> 0

wzyxIPM

*/



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
int n, m, k, w, q, po ;
string s, tree[10000];
void go(int depth){
	if (po < 0) return;
	tree[depth] += s[po];
	q = max(q, depth);
	if (s[po] >= 'a' && s[po] <= 'z') return;
	po--;
	go(depth + 1);
	po--;
	go(depth + 1);
}
int main() {

	Emsawy();
	cin >> w;
	while (w--){
		cin >> s;
		q = 0;
		po = s.size() - 1;
		go(0);
		string ans = "";
		while (q >= 0){
			ans += tree[q];
			tree[q].clear();
			q--;
		}
		cout << ans << endl;
	}
	return 0;
}
