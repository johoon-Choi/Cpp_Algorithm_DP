#include <iostream>
#include <vector>

// LIS = Longest Increasing Subsequence

using namespace std;

int N;
vector<int> A;
vector<int> left_LIS;
vector<int> right_LIS;
vector<int> bitonic_LIS;

int main() {
	cin >> N;
	A.assign(N + 1, 0);
	left_LIS.assign(N + 1, 1);
	right_LIS.assign(N + 1, 1);
	bitonic_LIS.assign(N + 1, 0);
	// LIS[k] : the max length of sequence at k'th index 

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int ans = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				left_LIS[i] = max(left_LIS[i], left_LIS[j] + 1);
			}
			//else if (A[i] == A[j]) LIS[i] = LIS[j];
		}
		bitonic_LIS[i] += left_LIS[i];
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = N; j > i; j--)
			if (A[i] > A[j])
				right_LIS[i] = max(right_LIS[i], right_LIS[j] + 1);
		bitonic_LIS[i] += right_LIS[i];

		ans = max(ans, bitonic_LIS[i]);
	}

	if (N > 1) cout << ans - 1;
	else cout << ans;
}