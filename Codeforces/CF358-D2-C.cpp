#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m;
V<pair<int,int> >v;
string ans[200005];
void go(int id){
	sort(allr(v));
	V<string>s(v.size());
	if (v.size() > 0) s[0] = "pushStack";
	if (v.size() > 1) s[1] = "pushQueue";
	if (v.size() > 2) s[2] = "pushFront";
	for (int i = 3; i < v.size(); i++)
		s[i] = "pushBack";
	for (int i = 0; i < v.size(); i++)
		ans[v[i].second] = s[i];
	if (id == -1) return;
	string put = "";
	if (v.size() > 0) put += "popStack";
	if (v.size() > 1) put += " popQueue";
	if (v.size() > 2) put += " popFront";
	if (v.size() > 2) ans[id] = "3 " + put;
	else if (v.size() > 1) ans[id] = "2 " + put;
	else if (v.size() > 0) ans[id] = "1 " + put;
	else ans[id] = "0";
	v.clear();
}
int main()
{
	Emsawy();
	while (cin >> n){
		int x;
		for (int i = 0; i < n; i++){
			sf(x);
			if (x == 0) go(i);
			else v.push_back(MP(x,i));
		}
		go(-1);
		for (int i = 0; i < n; i++)
			cout << ans[i] << endl;
	}
	return 0;
}
