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


class RowAndCoins {
public:
	string getWinner(string cells) {
		int a = cells[0] == 'A', b = cells[0] == 'B';
		for (int i = 1; i < cells.size(); i++){
			if (cells[i] != cells[i - 1]){
				if (cells[i] == 'A') a++;
				else b++;
			}
		}
		if (b > a) return "Bob";
		else return "Alice";
	}
};
