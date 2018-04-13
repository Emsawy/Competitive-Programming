#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 2e9+10;

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
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 100000 + 5;
int n, m, k, w;
char x[100], y[100];
int z1[100], z2[100];
int b1, b2, len1, len2, carry1, carry2;
int add(char *x, char *y, int b, int *z) {
	int carry = 0;
	for (int i = len1 - 1; i >= 0; i--) {
		z[i] = (x[i] + y[i] + carry - '0' * 2) % b;
		carry = (carry + x[i] + y[i] - '0' * 2) / b;
	}
	return carry;
}
bool same(int *a, int *b) {
	for (int i = 0; i < len1; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return carry1 == carry2;
}
int main() {

	Emsawy();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s %s %d %d", x, y, &b1, &b2);
		
		len1 = strlen(x);
		len2 = strlen(y);

		if (len1 > len2) {
			int endl = len2, endr = len1;
			while (endl--) {
				y[--endr] = y[endl];
			}
			while (endr--) {
				y[endr] = '0';
			}
			len2 = len1;
		}
		else if(len1 < len2) {
			int endl = len1, endr = len2;
			while (endl--) {
				x[--endr] = x[endl];
			}
			while (endr--) {
				x[endr] = '0';
			}
			len1 = len2;
		}
		carry1 = add(x, y, b1, z1);
		carry2 = add(x, y, b2, z2);
		if (same(z1, z2)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

