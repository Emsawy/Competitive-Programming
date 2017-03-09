/*

Taken from : BOBAS.
Boring partition:
Sort the array in non-increasing order. Array size is n, numbering starts from 1. If we kept all the integers in the same subsequence, the answer would be (a[1] + a[2]) — (a[n-1] + a[n]), which is the difference between the maximal and minimal possible sums, respectively. To make the difference smaller, we need to either : decrease the maximal sum or increase the minimal sum. Since h >= 0, moving a number to another subsequence can only increase the sums. Hence it's impossible to decrease the current maximal sum, so we should try to increase the minimal sum. To do that, we should move the smallest element, a[n], to the other subsequence. Now, a few different scenarios can happen:
1) Maximal sum remains a[1] + a[2], minimal sum becomes a[n-1] + a[n] + h, the difference becomes smaller (or equal, if h = 0).
2) Maximal sum remains a[1] + a[2], minimal sum becomes a[n-2] + a[n-1], the difference becomes smaller (or equal, if a[n-2] = a[n]).
3) Maximal sum becomes a[1] + a[n] + h, minimal sum becomes a[n-2] + a[n-1]. The difference can be larger, equal or smaller.
Moving more numbers to the other subsequence can't decrease the difference in any scenario. In conclusion, the answer is always either:
1) Keep everything in the same subsequence.
2) Keep everything in the same subsequence, except the smallest element.

*/


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

#define sz(v)		((int)((v).size()))
#define all(v)		((v).begin()), ((v).end())
#define allr(v)		((v).rbegin()), ((v).rend())
#define clr(v,d)	memset(v, d, sizeof(v))
#define sf(x)		scanf("%d", &x)
#define sf2(x,y)	scanf("%d %d", &x, &y)
#define sf3(x,y,z)	scanf("%d %d %d", &x, &y, &z)
#define sfll(x)		scanf("%I64d", &x)
#define sfll2(x,y)	scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)	scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)	(atan2((a).imag(), (a).real()))
#define vec(a,b)	((b)-(a))
#define length(a)	(hypot((a).imag(), (a).real()))
#define dp(a,b)		((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)		((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)	(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii		pair<int,int>
#define V		vector
#define MP		make_pair
#define X		real()
#define Y		imag()
typedef complex<double> Point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k;

int main()
{
	Emsawy();
	while (cin >> n >> k){
		V<pair<int, int> > p(n);
		for (int i = 0; i < n; i++){
			cin >> p[i].first;
			p[i].second = i;
		}
		sort(all(p));
		int ans = 0;
		int mx = 0, mn = oo;
		mx = max(mx, p[n - 1].first + p[0].first + k);
		mx = max(mx, p[1].first + p[0].first + k);
		mn = min(mn, p[n - 1].first + p[0].first + k);
		mn = min(mn, p[1].first + p[0].first + k);
		if (n > 2){
			mx = max(mx, p[n - 1].first + p[n - 2].first);
			mn = min(mn, p[n - 1].first + p[n - 2].first);
			mx = max(mx, p[1].first + p[2].first);
			mn = min(mn, p[1].first + p[2].first);
		}
		ans = mx - mn;
		V<int>an(n, 1);
		if (ans > (p[n - 1].first + p[n - 2].first) - (p[0].first + p[1].first))
			ans = (p[n - 1].first + p[n - 2].first) - (p[0].first + p[1].first);
		else
			an[0] = 2;
		V<int>an2(n);
		for (int i = 0; i < n; i++){
			an2[p[i].second] = an[i];
		}
		cout << ans << endl;
		for (int i = 0; i < n; i++){
			cout << an2[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}
