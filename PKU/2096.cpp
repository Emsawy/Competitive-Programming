#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

const int N = 1010;
int n, m, k, w,s;
double dp[N][N];

int main() {

	while (cin >> n >> s) {
		
		dp[n][s] = 0;
		for (int i = n; i >= 0; i--) {
			for (int j = s; j >= 0; j--) {
				dp[i][j] = (dp[i + 1][j + 1] + 1) * ((n - i) * (s - j)) / (n * s * 1.0);
				dp[i][j] += (dp[i + 1][j] + 1) * ((n - i) * j) / (n * s * 1.0);
				dp[i][j] += (dp[i][j + 1] + 1) * (i * (s - j)) / (n * s * 1.0);
				dp[i][j] += (dp[i][j] + 1) * (i * j) / (n * s * 1.0);
			}
		}
		cout << fixed << setprecision(4) << dp[0][0] << endl;
	}
	return 0;
}
