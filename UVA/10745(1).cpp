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
const ll mod = 1e9 + 7, oo = 1e9;
int n, m;
map<string, int>mp;
V<int>alph;
V<string>v;
void go(int id , string s , string me){
	if (id == 26){
		if (s == me) return;
		if (mp.find(s) != mp.end())
			mp[s] = -1;
		return;
	}
	string now = "";
	for (int i = 0; i <= alph[id];i++){
		go(id + 1, s + now , me);
		now += char(id + 'a');
	}
}
int main()
{
	Emsawy();
	string t;
	V<string>s;
	while (cin >> t){
		s.push_back(t);
		sort(all(t));
		mp[t] = int(s.size()) - 1;
	}
	for (int i = 0; i < s.size(); i++){
		alph.clear(), alph.resize(26);
		for (int j = 0; j < s[i].size(); j++)
			alph[s[i][j] - 'a']++;
		t = s[i];
		sort(all(t));
		go(0 , "" , t);
	}
	V<string>ans;
	for (auto it : mp){
		if (it.second == -1) continue;
		ans.push_back(s[it.second]);
	}
	sort(all(ans));
	for (auto it : ans)
		cout << it << endl;
	return  0;
}
