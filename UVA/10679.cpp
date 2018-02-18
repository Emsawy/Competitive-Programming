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
	cout << fixed << setprecision(6);
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
const ll N = 110000;
ll n, m, k, w;

const int S = 26*2;
struct Node
{
	V<int> items;
	int nxt[S], go[S];
	int p, c, link;
	int leaf;
	Node(){}
	Node(int p, int c) :p(p), c(c){
		link = leaf = -1;
		memset(nxt, -1, sizeof(nxt));
		memset(go, -1, sizeof(go));
	}
};
Node aho[N];
int nodeCount;
void init(){
	nodeCount = 0;
	aho[nodeCount++] = Node(0, -1);
}

void addString(string &s, int id){
	int cur = 0;
	for (char ch : s){
		int c = ch - 'a';
		if (ch >= 'A' && ch <= 'Z') c = ch - 'A' + 26;
		if (aho[cur].nxt[c] == -1){
			aho[nodeCount] = Node(cur, c);
			aho[cur].nxt[c] = nodeCount++;
		}
		cur = aho[cur].nxt[c];
	}
	aho[cur].items.push_back(id);
}
void bfs(){
	int cur = 0;
	queue<int> q;
	for (int i = 0; i < S; i++){
		if (aho[cur].nxt[i] != -1){
			aho[aho[cur].nxt[i]].link = 0;
			q.push(aho[cur].nxt[i]);
		}
	}
	while (!q.empty()){
		int p = q.front();
		q.pop();
		int now = aho[p].p;
		while (now > 0){
			now = aho[now].link;
			if (aho[now].nxt[aho[p].c] != -1){
				aho[p].link = aho[now].nxt[aho[p].c];
				for (auto it : aho[aho[p].link].items)
					aho[p].items.push_back(it);
				break;
			}
		}
		if (aho[now].nxt[aho[p].c] == -1)
			aho[p].link = 0;

		for (int i = 0; i < S; i++){
			if (aho[p].nxt[i] != -1)
				q.push(aho[p].nxt[i]);
		}
	}
}
V<int>ans;
void match(string & s){
	int cur = 0;
	for (auto ch : s){
		int c = ch - 'a';
		if (ch >= 'A' && ch <= 'Z') c = ch - 'A' + 26;
		while (cur > 0 && aho[cur].nxt[c] == -1)
			cur = aho[cur].link;
		if (aho[cur].nxt[c] != -1)
			cur = aho[cur].nxt[c];
		for (auto it : aho[cur].items)
			ans[it] = 1;
	}
}

int main() {

	Emsawy();
	int T;
	cin >> T;
	while (T--){
		string s, qu;
		init();
		cin >> s >> n;
		for (int i = 0; i < n; i++){
			cin >> qu;
			addString(qu, i);
		}
		bfs();
		ans.clear();
		ans.resize(n);
		match(s);
		for (int i = 0; i < n; i++){
			if (ans[i]) cout << "y\n";
			else cout << "n\n";
		}
	}

	return 0;
}
