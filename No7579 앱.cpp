#include <iostream>
#include <vector>
#include <iomanip>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define memory first
#define cost second

using namespace std;
typedef pair<int, int> PII;

const int cost_max = 1e4;
int N, M;
vector<PII> apps;
vector<int> dp;
// dp[c] : c 원이 드는 경우에 제거 가능한 최대 용량

int solve() {
	dp[apps[0].cost] = apps[0].memory;
	//for (int ii = 0; ii < 16; ii++)
	//	cout << dp[ii] << setw(3);
	//cout << '\n';
	for (int i = 1; i < N; i++) {
		for (int c = cost_max; c >= apps[i].cost; c--) {
			if (dp[c - apps[i].cost] != -1) {
				dp[c] = max(dp[c],
					dp[c - apps[i].cost] + apps[i].memory);
			}
		}

		if (dp[apps[i].cost] < apps[i].memory)
			dp[apps[i].cost] = apps[i].memory;
			//for (int ii = 0; ii < 16; ii++)
			//	cout << dp[ii] << setw(3);
			//cout << '\n';
		

	}
	for (int c = 0; c <= cost_max; c++)
		if (dp[c] >= M)
			return c;

	return 0;
}

int main() {
	fastio;

	cin >> N >> M;
	apps.resize(N, PII(0,0));
	dp.resize(cost_max + 1, -1);

	for (auto& e : apps) cin >> e.memory;
	for (auto& e : apps) cin >> e.cost;

	cout << solve();
}