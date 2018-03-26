#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#define all(v)	     ((v).begin()), ((v).end())
#define clr(v,d)     memset(v, d, sizeof(v))
#define V	         vector

const ll N = (1 << 18);
int n, m, k, w;
ll A[101][101], B[101][101], ans[101][101];

void mult(){
	for(int i= 0;i<n;i++){
		for(int j= 0;j<n;j++){

			for(int k = 0;k<n;k++){
				ans[i][j] += A[i][k] * B[k][j];
			}

		}
	}
}
ll sum(){
	ll ret = 0;
	for(int i= 0;i<n;i++){
		for(int j = 0;j<n;j++){
			ret += ans[i][j];
		}
	}
	return ret;
}

int main() {

	Emsawy();
	while (cin >> n) {
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>A[i][j];
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>B[i][j];
			}
		}
		mult();
		int q, u , v , val;
		char op;
		cin>>q;
		while(q--){
			cin>> op >> u >> v >> val;
			if(op == 'A'){
				ll rem = val - A[u][v];
				A[u][v] = val;
				for(int i = 0;i<n;i++){
					ans[v][i] += rem * B[v][i];
				}
				cout<<sum()<<endl;
			}
			else {
				ll rem = val - B[u][v];
				B[u][v] = val;
				for(int i = 0;i<n;i++){
					ans[i][u] += rem * A[i][u];
				}
				cout<<sum()<<endl;
			}
		}
	}

	return 0;
}
