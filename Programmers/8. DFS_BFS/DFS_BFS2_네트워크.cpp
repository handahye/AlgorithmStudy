#include <string.h>
#include <vector>
/*
1. i번(0~n-1)과 연결된 컴퓨터 체크
2. 연결된 컴퓨터 방문
3. 방금 방문한 컴퓨터에서 또 연결되는 컴퓨터가 있으면 방문
4. 연결가능한 모든 컴퓨터를 방문한 경우 answer++해줌
5. 1로 돌아가서 아직 방문하지 않은 컴퓨터를 기준으로 또 체크
*/
using namespace std;
int visit[201];
int curIdx = 0;
void dfs(int idx, vector<vector<int>> computers) {
	for (int j = 0; j<computers[idx].size(); j++) {
		if (idx == j) continue;
		if (computers[idx][j] == 1 && !visit[j]) {//현재 컴퓨터에서 연결되어 있고, 아직 방문하지 않은 컴퓨터들 중
			visit[j] = 1;//방문체크
			dfs(j, computers);
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i<n;i++) { //0~n번까지의 컴퓨터 중 아직 방문하지 않은 컴퓨터가 시작
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, computers);
			answer++;//네트워크 수 증가
		}
	}
	return answer;
}