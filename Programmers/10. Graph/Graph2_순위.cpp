#include <string>
#include <vector>
using namespace std;
int dist[101][101] = { 0 };

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for (int i = 0;i < results.size();i++) {
		int u, v;
		u = results[i][0];
		v = results[i][1];
		dist[u][v] = 1;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				if (dist[j][i] == 1 && dist[i][k] == 1)
					dist[j][k] = 1;
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			if (i == j) continue;
			else if (dist[i][j] == 1 || dist[j][i] == 1) cnt++;
		}
		if (cnt == n - 1) answer++;
	}
	return answer;
}