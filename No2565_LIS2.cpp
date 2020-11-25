#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
int ans = 0;

vector<int> pole_B; // condition of pole B after pole A being sorted
vector<int> LIS;
map<int, int> pole;

int main() {
	cin >> N;

	pole_B.assign(N + 1, 0);
	LIS.assign(N + 1, 1);

	for (int i = 1; i <= N; i++) {
		//		cin >> pole_A[i] >> pole_B[i];
		int inputA, inputB;
		cin >> inputA >> inputB;

		pole.insert(pair<int, int>(inputA, inputB));
	}

	map<int, int>::iterator iter;

	int i = 1;
	for (iter = pole.begin(); iter != pole.end(); iter++) {
		pole_B[i++] = iter->second;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++)
			if (pole_B[i] > pole_B[j])
				LIS[i] = max(LIS[i], LIS[j] + 1);

		ans = max(ans, LIS[i]);
	}

	cout << N - ans;
}