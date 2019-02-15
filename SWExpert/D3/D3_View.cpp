#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
/*
D3_View
*/
int map[1001] = { 0, };
int cal(int i) {
	int maxN = -987654321;
	maxN = max(max(map[i - 1], map[i - 2]), max(map[i + 1], map[i + 2]));
	int res = map[i] - maxN;
	if (res >= 1) return res;
	else return 0;
}
int main() {
	for (int t = 1; t <= 10; t++) {
		int res = 0;
		memset(map, 0, sizeof(map));
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> map[i];
		for (int i = 2; i < N - 2; i++) {
			res += cal(i);
		}
		cout << "#" << t << " " << res << endl;
	}

	return 0;
}