#include <iostream>
#include <vector>

// LIS = Longest Increasing Subsequence

using namespace std;

int N;
vector<int> A;
vector<int> LIS;

int main() {
	cin >> N;
	A.assign(N + 1, 0);
	LIS.assign(N + 1, 1);
	// LIS[k] : the max length of sequence at k'th index 

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int ans = 1;
	
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
			//else if (A[i] == A[j]) LIS[i] = LIS[j];
		}

		ans = max(ans, LIS[i]);
	}

	cout << ans;
}