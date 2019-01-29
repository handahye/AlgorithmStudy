#include <iostream>
#include<string.h>
using namespace std;
/*배열 크기때문에 계속 1개 틀렸다 ,, */
int map[1005][1005];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int  N, M;
		int res = 0;
		cin >> N >> M;
		//배열 돌면서 길이 2인 부분 없앰
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i + 2][j] = 1;
					map[i][j + 2] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0) res++;
		printf("#%d %d\n", t, res);
	}
	return 0;
}