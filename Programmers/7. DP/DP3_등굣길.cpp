#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int dist[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i<puddles.size(); i++)
		dist[puddles[i][0]][puddles[i][1]] = -1; //물 웅덩이
	dist[1][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == -1) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = (dist[i][j - 1] + dist[i - 1][j]) % 1000000007;
			//위와 왼쪽에서만 i,j 인덱스에 접근 가능하니까
		}
	}

	return dist[m][n];
}