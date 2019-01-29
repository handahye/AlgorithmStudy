#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<int> up, down;
		int map[101];
		cin >> N;
		for (int i = 0; i < N; i++) cin >> map[i];
		for (int i = 0; i < N-1; i++) {
			int cur = map[i];
			int next = map[i + 1];
			if (cur < next) up.push_back(next - cur);
			else down.push_back(cur - next);
		}
		sort(up.begin(), up.end(),compare);
		sort(down.begin(), down.end(), compare);
		int res1 = 0, res2 = 0;
		if (up.size() > 0) res1 = up[0];
		if (down.size() > 0) res2 = down[0];
		printf("#%d %d %d\n", t, res1, res2);
	}
	return 0;
}