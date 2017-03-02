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

#define sz(v) ((int)((v).size()))
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
int n, m, k;

/*
- I get the strings which separate with (,) 
- Find for each if they a valid Action or not 
- valid Action have one VERB(s) and have no (VERB) in it's first and last and has no (the or a) in last and has no (and) in it's first and last.

*/

map<string, bool>verb = { { "hate", 1 }, { "love", 1 }, { "know", 1 }, { "like", 1 }};
map<string, bool>verbs = { { "hates", 1 }, { "loves", 1 }, { "knows", 1 }, { "likes", 1 }};
map<string, bool>noun = { { "tom",1},{"jerry",1},{"goofy", 1},{"mickey", 1}, {"jimmy", 1 }, { "dog", 1 }, { "cat", 1 }, { "mouse", 1 } };
bool go(V<string> & v){
	int a = 0;
	if (v.back() == "a" || v.back() == "the" || verb[v.back()] || verb[v[0]] || v.back() == "and" || v[0] == "and") return 0;
	for (int i = 0; i < v.size(); i++)
		if (verb[v[i]] || verbs[v[i]]) a++;
	if (a != 1) return 0;

	for (int i = 0; i < v.size(); i++){
		if (v[i] == "a" || v[i] == "the"){
			if (noun[v[i + 1]] == 0) return 0;
			if (i + 2 < v.size() && v[i + 2] != "and" && (verb[v[i + 2]] == 0 && verbs[v[i + 2]] == 0))
				return 0;
			i += 2;
		}
		else {
			if (noun[v[i]] == 0)
				return 0;
			if (i + 1 < v.size() && v[i + 1] != "and" && (verb[v[i + 1]] == 0 && verbs[v[i + 1]] == 0))
				return 0;
			i++;
		}
	}
	return 1;
}
int main()
{
	Emsawy();
	string s;
	while (getline(cin, s)){
		stringstream ss;
		ss << s;
		V<V<string> > v;
		v.push_back(V<string>());
		while (ss >> s){
			if (s.back() == ','){
				if (s.size() > 1)s.pop_back(), v.back().push_back(s);
				v.push_back(V<string>());
				continue;
			}
			v.back().push_back(s);
		}
		bool ok = 1;
		for (int i = 0; i < v.size(); i++){
			if (v[i].size() == 0){
				ok = 0;
				break;
			}
			ok &= go(v[i]);
		}
		if (ok)puts("YES I WILL");
		else puts("NO I WON'T");
	}
	return 0;
}
