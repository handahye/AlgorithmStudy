#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	int T, N, K;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		vector<int> M;
		for (int i = 0; i < N; i++) {
			int m;
			cin >> m;
			M.push_back(m);
		}
		sort(M.begin(), M.end(), compare);
		float total = 0;
		for (int i = K - 1; i >= 0; i--) {
			total = (total + M[i]) / 2;
		}
		printf("#%d %f\n", t, total);

	}
	return 0;
}