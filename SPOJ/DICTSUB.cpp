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
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[]={1, -1, 0, 0, 1, -1, 1, -1};
int dy[]={0, 0, 1, -1, 1, -1, -1, 1};

V<V<pair<int, int> > > adj;
const ll N = 1000000 + 5;
ll n, m, k, w;
char sub[10001];
char s[10001];

int main() {

	Emsawy();
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%s", &n, s);
		int slen = strlen(s);
		for (int i = 0; i < n; i++){
			scanf("%s", sub);
			bool ok = 0;
			int sublen = strlen(sub), en = 0;
			for (int j = 0; j < sublen && !ok; j++){
				int loop = 0;
				while (j < sublen && isdigit(sub[j])) loop *= 10, loop += (sub[j] - '0'), j++;
				if (loop + en >= slen){
					ok = 1;
					break;
				}
				while (loop > 0){
					while (en < slen && sub[j] != s[en]) en++;
					if (en >= slen){
						ok = 1;
						break;
					}
					loop--;
					en++;
				}
			}
			if (ok == 0) printf( "YES\n" );
			else printf( "NO\n" );
		}
		printf("\n");
	}
	return 0;
}
