#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2100000000;
int tc;
vector<int> answer;
vector<int> sum;

int cost(int i, int j) {
	if (i > 0) return sum[j] - sum[i - 1];
	else return sum[j];
}

int DP(vector<int>& chaps) {
	int num = chaps.size();

	vector<vector<int>> dp;
	dp.assign(num, vector<int>(num, 0));

	// dp[k][k] == 0

	for (int i = 1; i < num; i++)
		dp[i - 1][i] = chaps[i] + chaps[i - 1];
	
	for (int j = 2; j < num; j++) {
		for (int i = 0; i < num - j; i++) {
			// (i, i + j)
			int I = i;
			int J = i + j;
			int ans = INF;

			for (int k = I; k < J; k++) {
				ans = min(ans, dp[I][k] + dp[k + 1][J] + cost(I, J));
			}
			dp[I][J] = ans;
		}
	}
	return dp[0][num - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	while (tc--) {
		int nums;
		cin >> nums;
		
		vector<int> input(nums);
		sum.assign(nums, 0);

		for (int i = 0; i < nums; i++) {
			cin >> input[i];

			if (i) sum[i] += sum[i - 1] + input[i];
			else sum[i] = input[i];
		}

		answer.push_back(DP(input));
	}

	for (auto elem : answer) cout << elem << '\n';
}