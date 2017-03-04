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
string a, b;
V<V<int> > adj1, adj2;
int node1 , node2;
void go1(){
	node1 = 0;
	adj1.resize(a.size() / 2 + 1);
	stack<int>st;
	st.push(node1);
	for (int i = 0; i < a.size(); i++){
		if (a[i] == '0'){
			adj1[st.top()].push_back(++node1);
			adj1[node1].push_back(st.top());
			st.push(node1);
		}
		else
			st.pop();
	}
}

void go2(){
	node2 = 0;
	adj2.resize(b.size() / 2 + 1);
	stack<int>st;
	st.push(node2);
	for (int i = 0; i < b.size(); i++){
		if (b[i] == '0'){
			adj2[st.top()].push_back(++node2);
			adj2[node2].push_back(st.top());
			st.push(node2);
		}
		else
			st.pop();
	}
}
int vs[5000] , cur = 0;
string tree1(int nd){
	if (vs[nd] == cur) return "";
	vs[nd] = cur;
	V<string>ret;
	for (int i = 0; i < adj1[nd].size(); i++){
		ret.push_back(('0' + tree1(adj1[nd][i]) + '1'));
	}
	sort(all(ret));
	string s = "";
	for (int i = 0; i < ret.size(); i++)
		s += ret[i];
	return s;
}
string tree2(int nd){
	if (vs[nd] == cur) return "";
	vs[nd] = cur;
	V<string>ret;
	for (int i = 0; i < adj2[nd].size(); i++){
		ret.push_back(('0' + tree2(adj2[nd][i]) + '1'));
	}
	sort(all(ret));
	string s = "";
	for (int i = 0; i < ret.size(); i++)
		s += ret[i];
	return s;
}
int main()
{
	Emsawy();
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		go1();
		go2();
		cur++;
		a = tree1(0);
		cur++;
		b = tree2(0);		
		if (a != b) puts("different");
		else puts("same");
		adj1.clear();
		adj2.clear();
	}
	return 0;
}
