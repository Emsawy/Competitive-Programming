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


class EllysCheckers {
public:
	string getWinner(string board) {
		int ans = 0;
		board.back() = '.';
		for (int i = 0; i < board.size(); i++){
			if (board[i] == 'o')
				ans += int(board.size()) - i - 1;
		}
		if (ans % 2)return "YES";
		else return "NO";
	}
};
