#include <string.h>
#include <vector>

using namespace std;
int visit[201];
void dfs(int idx, vector<vector<int>> computers) {
	for (int j = 0; j<computers[idx].size(); j++) {
		if (idx == j) continue;
		if (computers[idx][j] == 1 && !visit[j]) {
			visit[j] = 1;
			dfs(j, computers);
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i<computers.size();i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, computers);
			answer++;
		}
	}
	return answer;
}