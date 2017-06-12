
/*
    I have 4 dimension (0,1,2,3)(D,L,U,R) and used extra 5-th dimention to reflect the current node to it's neighbors
    nodes also used to store the final answer for each node from start position to the current position. 

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

V<V<pii> > adj;
int n, m, k, t, c , dj[10005][5];
pair<int, int> g[10005][4];
struct Node{
	int w, d, i;
	Node(int i, int d, int w) :i(i), d(d), w(w){}
	bool operator<(const Node & x) const{
		return MP(w, MP(d, i)) > MP(x.w, MP(d, i));
	}
};

int cmp(int x, int y){  // compressing
	return x * m + y;
}

int main()
{
	Emsawy();
	int sx, sy, ex, ey;
	while (cin >> n >> m >> sx >> sy >> ex >> ey){
		if (n + m + sx + sy + ex + ey == 0) break;
		int start = cmp(sx-1, sy-1);
		int end = cmp(ex-1, ey-1);

		for (int i = 0; i < n * m; i++)
			for (int j = 0; j < 5; j++)
				g[i][j] = MP(0, 0);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m - 1; j++){
				cin >> t;
				g[cmp(i, j)][3] = MP(t, cmp(i, j + 1));
				g[cmp(i, j+1)][1] = MP(t, cmp(i, j));
			}
			if (i == n - 1) continue;
			for (int j = 0; j < m; j++){
				cin >> t;
				g[cmp(i, j)][0] = MP(t, cmp(i + 1, j));
				g[cmp(i + 1, j)][2] = MP(t, cmp(i, j));
			}
		}

		for (int i = 0; i < n * m; i++)
			for (int j = 0; j < 5; j++)
				dj[i][j] = oo;

		priority_queue<Node> pq;
		pq.push(Node(start, 4, 0));
		dj[start][4] = 0;  // the distance from (start) to it self is zero in the 5-th dimension (5-th using base 1)
                       // but the distance from (start) to it self using others dimension will not be zero (it must go and back) 
		while (!pq.empty()){
			Node top = pq.top(); pq.pop();
		
			if (dj[top.i][top.d] > top.w) continue;
			if (top.d == 4){
				for (int i = 0; i < 4; i++){
					
          
        /*
          Note that there is more unvalid dirctions that i do with more expensive cost(doubled) to reflect the directions.
          I gerneralized it to go the four directions including it's dirction (this vaiolet the constrans of the problem that if i go int the same dirction i do not doubles the cost of the street)
          but this line will handle this cases 
        */
					if (g[top.i][i].first == 0) continue;
					
					int j = g[top.i][i].second;
					if (top.w + 2 * g[top.i][i].first < dj[j][i]){   // spreed the current node to it's four neighbors
						dj[j][i] = top.w + 2 * g[top.i][i].first;
						pq.push(Node(j, i, dj[j][i]));
					}

					if (top.w + 2 * g[top.i][i].first < dj[j][4]){ // get the current answer of the current node in the 5-th dimension
						dj[j][4] = top.w + 2 * g[top.i][i].first;
						pq.push(Node(j, 4, dj[j][4]));
					}
				}
			}
			else {

				if (g[top.i][top.d].first == 0) continue;

				int j = g[top.i][top.d].second;
				if (top.w + g[top.i][top.d].first < dj[j][top.d]){  // move any node has a direction (not the 5-th direction) to it's final node in the same direction
					dj[j][top.d] = top.w + g[top.i][top.d].first;
					pq.push(Node(j, top.d, dj[j][top.d]));
				}

				if (top.w + 2 * g[top.i][top.d].first < dj[j][4]){  // update my answer in the 5-th dimension 
					dj[j][4] = top.w + 2 * g[top.i][top.d].first;
					pq.push(Node(j, 4, dj[j][4]));
				}

			}
		}
		cout << "Case " << ++c << ": ";
		if (dj[end][4] == oo) cout << "Impossible" << endl;
		else cout << dj[end][4] << endl;
	}
	return 0;
}
