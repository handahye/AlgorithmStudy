#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
	vector<int> node[20002];
	int visit[20002] = { 0, };
	//연결된 노드들 체크
	for (int i = 0; i<edge.size(); i++) {
		int u = edge[i][0];
		int v = edge[i][1];
		node[u].push_back(v);
		node[v].push_back(u);
	}
	queue<int> q; //노드 번호
	q.push(1);
	visit[1] = 1; //1번 노드에서
	while (!q.empty()) {
		int u = q.front();//현재 노드 번호
		q.pop();

		for (int i = 0; i<node[u].size(); i++) {//현재 노드에서 연결된 노드들
			int next = node[u][i];
			if (visit[next] == 0) {//아직 방문하지 않은 노드들만 큐에 추가
				visit[next] = visit[u] + 1;//방문할 수 있는 노드의 간선 +1씩 해줌
				q.push(next);
			}
		}
	}
	int answer = 0, maxN = -98764321;
	for (int i = 1; i <= n; i++) maxN = max(maxN, visit[i]); //최대 간선 수 구하기
	for (int i = 1; i <= n; i++) if (visit[i] == maxN) answer++;//최대 간선 수를 갖는 노드 개수 구하기
	return answer;
}
