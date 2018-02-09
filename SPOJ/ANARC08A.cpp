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
const ll N = 100000 + 5;
int n, m, k, w;
string rotate(int id, int dir, string s){
	char c;
	switch (id)
	{
	case 1:
		if (dir == 1){
			c = s[0];
			s[0] = s[1], s[1] = s[4], s[4] = s[3], s[3] = c;
		}
		else {
			c = s[0];
			s[0] = s[3], s[3] = s[4], s[4] = s[1], s[1] = c;
		}
		break;
	case 2:
		if (dir == 1){
			c = s[1];
			s[1] = s[2], s[2] = s[5], s[5] = s[4], s[4] = c;
		}
		else {
			c = s[1];
			s[1] = s[4], s[4] = s[5], s[5] = s[2], s[2] = c;
		}
		break;
	case 3:
		if (dir == 1){
			c = s[3];
			s[3] = s[4], s[4] = s[7], s[7] = s[6], s[6] = c;
		}
		else {
			c = s[3];
			s[3] = s[6], s[6] = s[7], s[7] = s[4], s[4] = c;
		}
		break;
	case 4:
		if (dir == 1){
			c = s[4];
			s[4] = s[5], s[5] = s[8], s[8] = s[7], s[7] = c;
		}
		else {
			c = s[4];
			s[4] = s[7], s[7] = s[8], s[8] = s[5], s[5] = c;
		}
		break;
	}
	return s;
}
int id = 1;
const int eSize = 10;
const char cmp = '0';
struct Node{
	Node * edges[eSize];
	int leaf;
	Node(){
		for (int i = 0; i < eSize; i++)
			edges[i] = NULL;
		leaf = 0;
	}
};
void insert(Node * po, string & s, int idx){
	if (idx >= s.size()){
		po->leaf = id++;
		return;
	}
	if (po->edges[s[idx] - cmp] == NULL)
		po->edges[s[idx] - cmp] = new Node;
	insert(po->edges[s[idx] - cmp], s, idx + 1);
}
int Trie(Node * po, string &s, int idx){
	if (po == NULL) return 0;
	if (idx >= s.size()) return po->leaf;
	return Trie(po->edges[s[idx] - cmp], s, idx + 1);
}
Node * root;
string init = "123456789";
int lvl[1000000];
void bfs(){
	queue<string> q;
	insert(root, init, 0);
	q.push(init);
	int lv = 0;
	while (q.empty() == false){
		int size = q.size();
		for (int i = 0; i < size; i++){
			string s = q.front();
			q.pop();
			lvl[Trie(root, s, 0)] = lv;
			for (int i = 1; i <= 4; i++){
				for (int j = 1; j <= 2; j++){
					string r = rotate(i, j, s);
					if (Trie(root, r, 0)) continue;
					insert(root, r, 0);
					q.push(r);
				}
			}
		}
		lv++;
	}

}

int main() {

	Emsawy();
	root = new Node();
	bfs();
	string in;
	while (cin >> in){
		if (in[1] == '0') break;
		int mn = lvl[Trie(root, in, 1)];
		if (mn > in[0] - '0') cout << ++k << ". " << -1 << endl;
		else cout << ++k << ". " << mn << endl;
	}
	return 0;
}
