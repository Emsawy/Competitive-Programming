
/*
  - First consider each node as the root and get the minimum cost for each.
  - For each subtree in node X use greed algorithm to get the minimum answer.
  - greed algorithm:
    use have to chose the subtrees in node X with some order to get the optimal solution.
    chose first on maximum of (tot)(total number of needed solders) - (kill)(total number of died solders + remaning solders in castle)
    chose second on minimum of total number of needed solders.
    and sort them.
    get the subproblem answer.
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
const ll mod = ll(1e9 + 7), oo = ll(1e9), si = 1000000;

V<V<int > > adj;
int n, m, k, t, c;
int A[100], B[100];

bool comp(pair<int, int> &lhs, pair<int, int> rhs){
	if (lhs.first == rhs.first)
		return lhs.second < rhs.second;
	return lhs.first > rhs.first;
}

pair<int,int> go(int nd , int lst = -1){
	V<pair<int, int> > chose;
	for (int i = 0; i < adj[nd].size(); i++){
		int child = adj[nd][i];
		if (child == lst) continue;
		chose.push_back(go(child , nd));
	}
	sort(all(chose) , comp);
	int tot = A[nd], rem = A[nd] - B[nd];
	for (int i = 0; i < chose.size(); i++){
		if (rem > chose[i].second)
			rem -= chose[i].second - chose[i].first;
		else {
			tot += chose[i].second - rem;
			rem = chose[i].first;
		}
	}
	return MP(rem , tot);
}
int main()
{
	/*V<pair<int, int> > test = { { 10, 1 }, { 10, 2 }, { 11, 1 }, { 11, 2 } };
	sort(all(test), comp);*/

	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < n; i++){
			cin >> A[i] >> B[i] >> t;
			B[i] += t;
			A[i] = max(A[i], B[i]);
		}
		int u, v;
		for (int i = 1; i < n; i++){
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans = (1 << 31) - 1;
		for (int i = 0; i < n; i++){
			ans = min(ans, go(i, -1).second);
		}
		cout <<"Case "<< ++c <<": "<< ans << endl;
	}
	return 0;
}
