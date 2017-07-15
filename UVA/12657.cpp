
/*
another solution, i will try later
http://qkxue.net/info/113260/UVA-Boxes-Line-12657
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
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c;

struct Node{
	int vl;
	Node *lf, *ri;
	Node(){}
} lst[100005];

void Insert_lf(Node * a, Node * l){
	l->lf->ri = a, a->lf = l->lf;
	a->ri = l, l->lf = a;
}
void Insert_ri(Node * a, Node * r){
	r->ri->lf = a, a->ri = r->ri;
	a->lf = r, r->ri = a;
}

void Remove(Node * a){
	a->lf->ri = a->ri;
	a->ri->lf = a->lf;
}

void Swap(Node * a, Node * b){
	if (a->ri != b && a->lf != b){
		a->lf->ri = a->ri->lf = b;
		b->lf->ri = b->ri->lf = a;
		swap(a->lf, b->lf);
		swap(a->ri, b->ri);
	}
	else if (a->ri == b){
		a->lf->ri = b, b->ri->lf = a;
		a->ri = b->ri, b->lf = a->lf;
		a->lf = b, b->ri = a;
	}
	else{
		a->ri->lf = b, b->lf->ri = a;
		a->lf = b->lf, b->ri = a->ri;
		a->ri = b, b->lf = a;
	}
}

void link(int idx, int vl){
	lst[idx].vl = vl;
	lst[idx].ri = &lst[idx + 1];
	lst[idx].lf = &lst[idx - 1];
}
void InputDate(int N){
	//int x;
	lst[0].lf = &lst[N], lst[0].ri = &lst[1];
	for (int i = 1; i < N; i++){
		//cin >> x;
		link(i, i);
	}
	lst[N].vl = N, lst[N].ri = &lst[0], lst[N].lf = &lst[N - 1];
}
void Print(){
	Node * now = &lst[0];
	while (now->ri != &lst[0]){
		cout << now->ri->vl << " ";
		now = now->ri;
	}
	cout << endl;
}
ll ans(bool reversed){
	ll ret = 0;
	bool index = 1;
	if (!reversed){
		Node * now = &lst[0];
		while (now->ri != &lst[0]){
			if (index) ret += now->ri->vl;
			index = !index;
			now = now->ri;
		}
		return ret;
	}
	Node * now = &lst[0];
	while (now->lf != &lst[0]){
		if (index) ret += now->lf->vl;
		index = !index;
		now = now->lf;
	}
	return ret;
}


int main()
{
	Emsawy();
	while (sf2(n, m) != EOF){
		InputDate(n);
		bool reversed = 0;

		int x, y;
		while (m--){
			sf(t);
			if (t == 1){
				sf2(x, y);
				if (reversed){
					Remove(&lst[x]);
					Insert_ri(&lst[x], &lst[y]);
				}
				else {
					Remove(&lst[x]);
					Insert_lf(&lst[x], &lst[y]);
				}
			}
			else if (t == 2){
				sf2(x, y);
				if (reversed){
					Remove(&lst[x]);
					Insert_lf(&lst[x], &lst[y]);
				}
				else {
					Remove(&lst[x]);
					Insert_ri(&lst[x], &lst[y]);
				}
			}
			else if (t == 3){
				sf2(x, y);
				Swap(&lst[x], &lst[y]);
			}
			else reversed = !reversed;
		}
		ll now = ans(reversed);
		printf("Case %d: %lld\n", ++c, now);
		//Print();
	}

	return 0;
}
