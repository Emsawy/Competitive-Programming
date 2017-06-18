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

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c;
int BIT[200005], g[200005], suf[200005], prv[200005], si = 1;
void update(int idx, int vl){
	while (idx <= si){
		BIT[idx] = max(vl, BIT[idx]);
		idx += (idx & -idx);
	}
}

int get(int idx){
	int sum = 0;
	while (idx > 0){
		sum = max(sum , BIT[idx]);
		idx -= (idx & -idx);
	}
	return sum;
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n;
		map<int, int>cord;
		for (int i = 0; i < n; i++){
			cin >> g[i];
			cord[g[i]];
		}
		si = 1;
		for (map<int, int>::iterator it = cord.begin(); it != cord.end(); it++){
			it->second = si++;
		}
		for (int i = 0; i < n; i++)
			g[i] = cord[g[i]];

		prv[0] = suf[n - 1] = 1;
		
		for (int i = 1; i < n; i++){
			prv[i] = 1;
			if (g[i] > g[i - 1])
				prv[i] += prv[i - 1];
		}

		for (int i = n - 2; i >= 0; i--){
			suf[i] = 1;
			if (g[i] < g[i + 1])
				suf[i] += suf[i + 1];
		}

		int ans = 0;
		for (int i = 0; i < n; i++){
			ans = max(ans, suf[i] + get(g[i] - 1));
			update(g[i], prv[i]);
		}
		cout << ans << endl;
		clr(BIT, 0);
	}
	return 0;
}
