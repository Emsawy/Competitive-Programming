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
int n, m, k, t;
char g[4][4];

int check(){

	char ch;
	int cnt;
	for (int i = 0; i < 4; i++){
		cnt = 0,ch = g[i][0];
		for (int j = 0; j < 4; j++){
			if (ch == g[i][j]) cnt++;
		}
		if (cnt == 4 && ch != '.')
			return (ch == 'x' ? 1 : -1);
	}

	for (int i = 0; i < 4; i++){
		cnt = 0,ch = g[0][i];
		for (int j = 0; j < 4; j++){
			if (ch == g[j][i]) cnt++;
		}		
		if (cnt == 4 && ch != '.')
			return (ch == 'x' ? 1 : -1);
	}

	cnt = 0, ch = g[0][0];
	for (int j = 0; j < 4; j++){
		if (ch == g[j][j]) cnt++;
	}		
	if (cnt == 4 && ch != '.')
		return (ch == 'x' ? 1 : -1);

	cnt = 0, ch = g[0][3];
	for (int j = 0; j < 4; j++){
		if (ch == g[j][3 - j]) cnt++;
	}
	if (cnt == 4 && ch != '.')
		return (ch == 'x' ? 1 : -1);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (g[i][j] == '.')
				return 2;

	return 0;
}

int go(bool pl, int alpha = -oo, int beta = oo){

	if (alpha >= beta) return (pl ? -oo : oo);
	int ret = check();
	if (ret != 2) return ret;

	int res = (pl ? -oo : oo);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (g[i][j] != '.')continue;
			if (pl){
				g[i][j] = 'x';
				res = max(res, go(!pl, max(alpha,res), beta));
				g[i][j] = '.';
			}
			else{
				g[i][j] = 'o';
				res = min(res, go(!pl, alpha, min(beta,res)));
				g[i][j] = '.';
			}
		}
	}
	return res;
}

int main()
{
	Emsawy();
	char c;
	while (cin >> c){
		if (c == '$')break;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> g[i][j];

		char ans[6];
		for (int i = 0; i < 5; i++) ans[i] = '#';
		ans[5] = '\0';
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (g[i][j] != '.') continue;
				g[i][j] = 'x';
				if (go(0) > 0){
					sprintf(ans, "(%d,%d)", i, j);
					c = '!';
					break;
				}
				g[i][j] = '.';
			}
			if (c == '!') break;
		}
		cout << ans << endl;
	}
	return 0;
}
