#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;
const int mx = 1000005;
int red[mx], jump[mx];

int find(int x){
	return !red[x] ? x : jump[x] = find(jump[x]);
}

class RightTriangle {
public:
	long long triangleCount(int places, int points, long long a, long long b, long long c) {

		memset(red, 0, sizeof red);
		int P = places, count = 0;

		for (int i = 0; i < P; i++){
			jump[i] = (i + 1) % P;
		}
		for (int i = 0; i < points; i++)
			p[find((a * i * i + b * i + c) % P)] = true;
		
		for (int i = 0; i < P / 2; i++)
			if (red[i] && red[i + P / 2])
				cout++;
		return P % 2 == 0 ? (long long)count * (points - 2) : 0;
	}
};
