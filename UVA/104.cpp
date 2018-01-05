
/*

used floyed warshal plus new dimension [l], which indicate the depth or the lenght of the sequence from i -> j

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
int n, m, k, w;
const int N = 100 + 5;
double f[N][N][N];
int src, sink;
int path[N][N][N];

int main()
{
	Emsawy();
	while (cin >> n ){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j){
					f[i][j][0] = 1;
					continue;
				}
				cin >> f[i][j][0];
			}
		}
		clr(path, 0);
		for (int l = 1; l < n; l++){
			for (int k = 0; k < n; k++){
				for (int i = 0; i < n; i++){
					for (int j = 0; j < n; j++){
						if (f[i][j][l] < f[i][k][l - 1] * f[k][j][0]){
						
							f[i][j][l] = f[i][k][l - 1] * f[k][j][0];
							path[i][j][l] = k;
							if (f[0][1][l] >= 1.0){
								int st = 0;
							}
						}
					}
				}
			}
		}
		int dl = 0, ok = 1;
		for (int l = 1; l < n && ok; l++){
		for (int i = 0; i < n && ok; i++){
				if (f[i][i][l] > 1.01){
						src = sink = i, dl = l;
						ok = 0;
				}
			}
		}

		if (ok == 1){
			cout << "no arbitrage sequence exists" << endl;
			clr(f, 0.0);
			continue;
		}
		V<int > ans;
		while (path[src][sink][dl]){
			ans.push_back(path[src][sink][dl]);
			sink = path[src][sink][dl--];
		}
		cout << src + 1 << " ";
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i] + 1 << " ";
		}
		cout << src + 1 << "\n";
		clr(f, 0.0);
	}
	return 0;
}
