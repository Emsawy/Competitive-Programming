
/*
* it can be solved using dp with probabilities. 
* There is two cases, First cases when a equal b and second cases when a not equal b
* x = all possible moves = (n*(n-1))/2
* state (id , yes) -> the prob. to length id and a in it's b position if yes equal 1.  
* when a == b
*    which mean -> I am in my target position and current postion at the same time
*   There is two transitions for two cases (if yes = 0 and yes = 1)
*     If yes = 1 (i am in my initial position (a) )
*         First transition 	ret += go(id + 1, 1) * g1; g1 = ((n - 1)*(n - 2) / 2) / x , i can be in my position with swaping all others pairs (n-1) and yes = 1
*	        second transition	ret += go(id + 1, 0) * g2; g2 = (n - 1) / x , i can go in any others (n - 1) positions, and yes = 0 so i not in target position (b)
*     If yes = 0 (i am not in my position)
*         First transition 	ret += go(id + 1, 1) * (1.0 / x); , i can go to the target position with value (1/x)
*         second transition ret += go(id + 1, 0) * g3; g3 =  ((n - 1)* (n) / 2.0 - 1) / x; i can go to all the others pairs except my target poistion
* when a != b
*   There is three transitions if yes = 0
*     If yes = 0 i am not in target position (b)
*         First transition 	ret += go0(id + 1, 0) * g1; is the same g1 above , but i go with yes = 0 , which mean i stand in my position and not in my (b) position
*         second transition	ret += go0(id + 1, 0) * (n - 2) / x; can go to all others pos. except target and current position , and yes = 0
*         Third transition	ret += go0(id + 1, 1) * (1.0 / x); can go to my target position with prob. (1/x) and yes = 1
*     If yes = 1 , I am in my target position
*         only one transition.
*         	return ret = go(id, 1); -> which mean that i am in the same situation , i am in my target position and current postion at the same time
*/

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

using namespace std;


class RandomSwaps {
public:
	double n , m;
	double g1, g2, g3, x;
	double dp[100005][2];
	double go(int id, bool yes = 1){
		if (id == m) return yes;
		double &ret = dp[id][yes];
		if (ret != -1) return ret;
		ret = 0;
		if (yes){
			ret += go(id + 1, 1) * g1;
			ret += go(id + 1, 0) * g2;
		}
		else {
			ret += go(id + 1, 1) * (1.0 / x);
			ret += go(id + 1, 0) * g3;
		}
		return ret;
	}
	double dp0[100005][2];
	double go0(int id, bool yes = 0){
		if (id == m) return yes;
		double &ret = dp0[id][yes];
		if (ret != -1) return ret;
		ret = 0;
		if (!yes){
			ret += go0(id + 1, 0) * g1;
			ret += go0(id + 1, 0) * (n - 2) / x;
			ret += go0(id + 1, 1) * (1.0 / x);
		}
		else
			return ret = go(id, 1);
		//cout << fixed << setprecision(9);
		return ret;
	}
	double getProbability(int arrayLength, int swapCount, int a, int b) {
		m = swapCount;
		n = arrayLength;
		x = (n - 1) * n / 2;
		g1 = ((n - 1)*(n - 2) / 2) / x;
		g2 = (n - 1) / x;
		g3 = ((n - 1)* (n) / 2.0 - 1) / x;
		for (int i = 0; i < m; i++){
			dp[i][0] = dp[i][1] = -1;
			dp0[i][0] = dp0[i][1] = -1;
		}
		//cout << fixed << setprecision(9);
		if (a == b)
			return go(0, 1);
		return go0(0, 0);
	}
};
