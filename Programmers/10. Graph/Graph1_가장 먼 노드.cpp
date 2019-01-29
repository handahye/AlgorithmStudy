#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
	vector<int> node[20002];
	int visit[20002] = { 0, };
	multimap<int, int, greater<int>> mm;//key: 간선수, value: 노드
	for (int i = 0; i<edge.size(); i++) {
		int u = edge[i][0];
		int v = edge[i][1];
		node[u].push_back(v);
		node[v].push_back(u);
	}
	queue<pair<int, int>> q; //노드, 간선수
	q.push({ 1,1 });
	while (!q.empty()) {
		int u = q.front().first;
		int edgeNum = q.front().second;
		q.pop();

		if (visit[u]) continue;
		visit[u] = 1;
		mm.insert({ edgeNum, u });

		for (int i = 0; i<node[u].size(); i++) {
			int next = node[u][i];
			if (!visit[next]) {
				q.push({ next,edgeNum + 1 });
			}
		}
	}
	auto iter = mm.begin();
	int maxN = iter->first;
	return mm.count(maxN);
}
