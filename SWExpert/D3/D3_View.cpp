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
	//체크해야 하는 범위 중 가장 큰 건물 높이를 체크해놓음
	maxN = max(max(map[i - 1], map[i - 2]), max(map[i + 1], map[i + 2]));
	int res = map[i] - maxN; //현재 건물 - 범위 중 가장 큰 건물
	if (res >= 1) return res; // 그 값이 1이상이면 그 값을 리턴
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