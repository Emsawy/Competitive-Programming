#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);   // don't use scanf & printf
	cin.tie(0);
	cout.tie(0);
}

#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define clr(v,d)     memset(v, d, sizeof(v))
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;

V<V<int> > adj;
typedef long long ll;
const ll mod = 1e9 + 7, oo = 1e9, N = 200000 + 5;
int n, m;
char st1[N], st2[N];

bool Strcmp(int s1, int e1, int s2, int e2){
	for (int i = s1; i <= e1; i++){
		if (st1[i] != st2[s2++]) return 0;
	}
	return 1;
}
bool eq(int s1, int e1, int s2, int e2){
	if (Strcmp(s1,e1,s2,e2)) return 1;
	if ((e1 - s1 + 1) % 2) return 0;
	int ms1 = s1 + (e1 - s1) / 2;
	int ms2 = s2 + (e2 - s2) / 2;
	if (eq(s1, ms1, s2, ms2) && eq(ms1 + 1, e1, ms2 + 1, e2)) return 1;
	if (eq(s1, ms1, ms2 + 1, e2) && eq(ms1 + 1, e1, s2, ms2)) return 1;
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> st1 >> st2){
		if (eq(0, strlen(st1) - 1, 0, strlen(st2) - 1)) puts("YES");
		else puts("NO");
	}
	return 0;
}
