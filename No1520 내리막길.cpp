#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int n, m;
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };
vector<vector<int>> H;
vector<vector<int>> dp;

bool isSafe(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int solve(int i, int j) {
	if (i == n - 1 && j == m - 1) return 1;
	if (dp[i][j] == -1) {
		dp[i][j] = 0;
		//else if (dp[i][j]) return dp[i][j];

		for (int d = 0; d < 4; d++) {
			int next_i = i + di[d];
			int next_j = j + dj[d];

			if (isSafe(next_i, next_j)) {
				if (H[next_i][next_j] < H[i][j]) {
					dp[i][j] += solve(next_i, next_j);
				}
			}
		}
	}
	cout << " ( " << i << ", " << j << " )" << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(4) << dp[i][j];
		cout << '\n';
	}
	return dp[i][j];
}

//for (int i = 0; i < n; i++) {
//	for (int j = 0; j < m; j++)
//		cout << dp[i][j] << ' ';
//	cout << '\n';
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	H.assign(n, vector<int>(m, 0));
	dp.assign(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> H[i][j];

	cout << solve(0, 0);

	//cout << '\n' << '\n' << " °á°úÃ¢" << '\n' ;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		cout << ' ' << dp[i][j] << "  ";
	//	cout << '\n';
	//}
}