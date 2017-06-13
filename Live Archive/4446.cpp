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

V<V<pii> > adj;
int n, m, k, t, c, g, u;

char ch;
enum Gates{ And, Or, Xor, Not, stuckZero, stuckOne, Invert , Idel };

struct Gat{
	string i1, i2;
	Gates typ , smash;
	Gat(){};
	Gat(string i1, string i2, Gates typ) :i1(i1), i2(i2), typ(typ), smash(Idel){}
	Gat(string i1, Gates typ) :i1(i1), i2("!"), typ(typ), smash(Idel){}
};

V<Gat> in;
V<V<int> > test;
void Inputs(){
	string i1, i2;
	cin >> ch;
	if (ch == 'a'){
		cin >> i1 >> i2;
		in.push_back(Gat(i1, i2, (And)));
	}
	else if (ch == 'o'){
		cin >> i1 >> i2;
		in.push_back(Gat(i1, i2, (Or)));
	}
	else if (ch == 'x'){
		cin >> i1 >> i2;
		in.push_back(Gat(i1, i2, (Xor)));
	}
	else{
		cin >> i1;
		in.push_back(Gat(i1, Not));
	}
}
int cv(string s){
	return stoi(s.substr(1));
}
bool Calculate(Gat p , int tst){
	bool left, right;
	if (p.i1[0] == 'g')
		left = Calculate(in[cv(p.i1) - 1], tst);
	else if (p.i1[0] == 'i')
		left = test[tst][cv(p.i1) - 1];

	if (p.i2[0] == 'g')
		right = Calculate(in[cv(p.i2) - 1], tst);
	else if (p.i2[0] == 'i')
		right = test[tst][cv(p.i2) - 1];
	
	bool ret;
	if (p.typ == And) ret = left & right;
	else if (p.typ == Or) ret = left | right;
	else if (p.typ == Xor) ret = left ^ right;
	else ret = !left;

	if (p.smash == stuckOne) return 1;
	else if (p.smash == stuckZero) return 0;
	else if (p.smash == Invert) return !ret;
	else return ret;
}
int main()
{
	Emsawy();
	while (cin >> n >> g >> u){
		if (n + g + u == 0) break;
		for (int i = 0; i < g; i++)
			Inputs();
	
		V<int>out(u);
		for (int i = 0; i < u; i++)
			cin >> out[i];
		
		int B;
		cin >> B;
		for (int i = 0; i < B; i++){
			test.push_back(V<int>(u+n));
			for (int j = 0; j < n + u; j++){
				cin >> test[i][j];
			}
		}
		cout << "Case " << ++c << ": ";
		int cnt = 0, ans = -1 , error;
		for (int i = 0; i < g; i++){
			for (int j = 0; j < 3; j++){
				if (j == 0) in[i].smash = stuckOne;
				else if (j == 1) in[i].smash = stuckZero;
				else in[i].smash = Invert;
				bool ok = 0;
				for (int q = 0; q < B; q++){
					for (int r = 0; r < u; r++){
						if (Calculate(in[out[r] - 1], q) != test[q][r + n]){
							ok = 1;
							break;
						}
					}
					if (ok) break;
				}
				in[i].smash = Idel;
				if (!ok){
					ans = i+1;
					error = j;
					cnt++;
				}
				if (cnt > 1) break;
			}
			if (cnt > 1) break;
		}

		if (cnt == 0) cout << "No faults detected\n";
		else if (cnt == 1){
			if (error == 0) printf("Gate %d is failing; output stuck at 1\n", ans);
			else if (error == 1) printf("Gate %d is failing; output stuck at 0\n", ans);
			else  printf("Gate %d is failing; output inverted\n", ans);
		}
		else cout << "Unable to totally classify the failure\n";

		in.clear();
		test.clear();
	}
	return 0;
}
