
/*
with masking the grid 4*4 can solve it with dp
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15
- so the dp[state][player] is the answer of the gird (state) which start playing with (player).
- vector moves has all possible moves.
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

V<V<int> > adj;
const ll N = 1000;
int n, m, k, w;
V<int>moves;
void build(){
	for (int i = 1; i < 3; i++){
		for (int j = 1; j < 3; j++){
			moves.push_back((1 << (i * 4 + j)));
		}
	}
	for (int i = 0; i < 4; i++){
		int cur = 0;
		cur |= (1 << i);
		moves.push_back(cur);
		cur |= (1 << (4 + i));
		moves.push_back(cur);
		cur |= (1 << (8 + i));
		moves.push_back(cur);
	}
	for (int i = 0; i < 4; i++){
		int cur = 0;
		cur |= (1 << (12 + i));
		moves.push_back(cur);
		cur |= (1 << (8 + i));
		moves.push_back(cur);
		cur |= (1 << (4 + i));
		moves.push_back(cur);
	}

	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < 3; i++){
		c |= (1 << (0 + i));
		a |= (1 << (4 + i));
		b |= (1 << (8 + i));
		d |= (1 << (12 + i));
		moves.push_back(a);
		moves.push_back(b);
		moves.push_back(c);
		moves.push_back(d);
	}
	a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < 3; i++){
		c |= (1 << (3 - i));
		a |= (1 << (7 - i));
		b |= (1 << (11 - i));
		d |= (1 << (15 - i));
		moves.push_back(a);
		moves.push_back(b);
		moves.push_back(c);
		moves.push_back(d);
	}
}

int dp[(1 << (17)) + 20][2];

int play(int state, bool player){
	if (state == 0)
		return player;
	if (dp[state][player] != -1) return dp[state][player];
	if (player) dp[state][player] = 0;
	else dp[state][player] = 1;
	for (int i = 0; i < moves.size(); i++){
		if ((state & moves[i]) == moves[i]){
			if (player) dp[state][player] = max(dp[state][player], play(state ^ moves[i], !player));
			else dp[state][player] = min(dp[state][player], play(state ^ moves[i], !player));
		}
	}
	return dp[state][player];
}
int main() {

	Emsawy();
	build();
	clr(dp, -1);
	cin >> n;
	while (n--){
		char g[4][4];
		int incode = 0;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				cin >> g[i][j];
				if (g[i][j] == '.'){
					incode |= (1 << (i * 4 + j));
				}
			}
		}
		if (play(incode, 1)) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}
	return 0;
}
