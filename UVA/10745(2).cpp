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
V<string>in , ans;
struct Node{
	Node * edges[12];
	vector<int>leafs;
	Node(){
		for (int i = 0; i < 12; i++)
			edges[i] = NULL;
	}
};
void insert(Node * po, V<int>g, int idx , int id){
	if (idx == g.size()){
		po->leafs.push_back(id);
		return;
	}
	if (po->edges[g[idx]] == NULL)
		po->edges[g[idx]] = new Node;
	insert(po->edges[g[idx]],g, idx + 1 , id);
}
void Clear(Node * po, V<int>g ,int idx , bool tk){
	if (idx == 26){
		if (tk){
			for (int i = 0; i < po->leafs.size(); i++){
				in[po->leafs[i]] = "-1";
			}
			po->leafs.clear();
		}
		return;
	}
	for (int i = 0; i <= g[idx]; i++){
		if (po->edges[i])
			Clear(po->edges[i], g, idx + 1, tk | (i < g[idx]));
	}
}
void get(Node * po, int idx){
	if (idx == 26){
		if (po->leafs.size() == 1)
			ans.push_back(in[po->leafs[0]]);
		return;
	}
	for (int i = 0; i < 11; i++){
		if (po->edges[i]){
			get(po->edges[i], idx + 1);
		}
	}
}
int main()
{
	Emsawy();
	string s;
	Node * root = new Node();
	while (cin >> s){
		in.push_back(s);
		V<int>g(26);
		for (int i = 0; i < s.size(); i++)
			g[s[i] - 'a']++;
		insert(root, g, 0, in.size() - 1);
	}
	for (int i = 0; i < in.size(); i++){
		if (in[i] == "-1") continue;
		V<int>g(26);
		for (int j = 0; j < in[i].size(); j++)
			g[in[i][j] - 'a']++;
		Clear(root, g, 0, 0);
	}
	get(root, 0);
	sort(all(ans));
	for (auto it : ans)
		cout << it << endl;
	return 0;
}
